#ifndef MODULE_DOUBLE_H
#define MODULE_DOUBLE_H

#include <systemc.h>

SC_MODULE(ModuleDouble)
{

  sc_event A, B, Aack, Back;

  SC_CTOR(ModuleDouble)
  {
    SC_THREAD(A_th);
    SC_THREAD(B_th);

    SC_METHOD(A_mt);
  }

  void A_th(void);
  void B_th(void);
  void A_mt(void);
};

void ModuleDouble::A_th()
{
  while (true)
  {
    wait(3, SC_MS);
    A.notify();
    wait(sc_time(3, SC_MS), Aack);
  }
}

void ModuleDouble::B_th()
{
  while (true)
  {
    wait(2, SC_MS);
    B.notify();
    wait(sc_time(2, SC_MS), Back);
  }
}

void ModuleDouble::A_mt()
{
  auto event = "A";

  if (A.triggered())
  {
    event = "A";
    next_trigger(B);
    Aack.notify();
  }
  else
  {
    event = "B";
    next_trigger(A);
    Back.notify();
  }

  cout << "At " << sc_time_stamp() << " " << event << " fired" << endl;
}
#endif
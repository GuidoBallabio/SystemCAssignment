#ifndef MODULE_SINGLE_H
#define MODULE_SINGLE_H

#include <systemc.h>

SC_MODULE(ModuleSingle)
{

  sc_int<4> counter;
  sc_event event;

  SC_CTOR(ModuleSingle)
  {
    SC_THREAD(thread);

    SC_METHOD(method);
    sensitive << event;
  }
  void thread(void);
  void method(void);
};

void ModuleSingle::thread()
{
  while (true)
  {
    wait(2, SC_MS);
    event.notify();
  }
}

void ModuleSingle::method()
{
  counter++;
  cout << counter << " at " << sc_time_stamp() << endl; 
}

#endif
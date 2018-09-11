#ifndef STIMULUS_H
#define STIMULUS_H

#include <systemc.h>

#include "../util/param.h"
#include "../util/tools.h"

SC_MODULE(Stimulus)
{
  sc_in<bool> clk;
  sc_out<bool> reset, stimulus_out;

  SC_CTOR(Stimulus)
  {
    SC_THREAD(test_cases)
  }

  void test_cases();
};

void Stimulus::test_cases()
{
  cout << "easy start" << endl;

  reset->write(true);
  wait(clk.posedge_event());
  reset->write(false);
  wait(CLK_PERIOD, SC_NS);

  stimulus_out->write(true);
  wait(CLK_PERIOD * 40, SC_NS);

  cout << "calm before the resets" << endl;
  stimulus_out->write(false);
  wait(CLK_PERIOD * 10, SC_NS);

  stimulus_out->write(true);
  wait(CLK_PERIOD * 10, SC_NS);
  while (random_bool(0.95))
  {
    cout << "reset!" << endl;
    reset->write(true);
    wait(CLK_PERIOD * 2, SC_NS);
    reset->write(false);
    wait(CLK_PERIOD * (random_int() % 20), SC_NS);
  }

  cout << "ending" << endl;
  stimulus_out->write(false);
}

#endif

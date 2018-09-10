#ifndef MASTER_H
#define MASTER_H

#include <systemc.h>
#include <random>

#include "../util/param.h"

SC_MODULE(Master)
{

  sc_in<bool> stimulus_in; //just for simulation
  sc_in<bool> clk, ready, reset;
  sc_out<bool> valid;
  sc_out<sc_int<DATA_BITS>> data;
  sc_out<sc_int<ERROR_BITS>> error;
  sc_port<sc_signal_out_if<sc_int<CHANNEL_BITS>>, 0> out_ch;

  SC_CTOR(Master)
  {
    SC_THREAD(generate);
  }

  void generate(void);
};
#endif
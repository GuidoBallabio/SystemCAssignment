#ifndef SLAVE_H
#define SLAVE_H

#include <systemc.h>

#include "../util/param.h"

SC_MODULE(Slave)
{

  sc_in<bool> clk, valid, reset;
  sc_out<bool> ready;
  sc_in<sc_int<DATA_BITS>> data;
  sc_in<sc_int<ERROR_BITS>> error;
  sc_port<sc_signal_in_if<sc_int<CHANNEL_BITS>>, 0> in_ch;

  SC_CTOR(Slave)
  {
    SC_THREAD(consume);
  }

  void consume(void);
};
#endif
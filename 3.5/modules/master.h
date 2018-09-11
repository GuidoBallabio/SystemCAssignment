#ifndef MASTER_H
#define MASTER_H

#include <systemc.h>

#include "adapter.h"
#include "../util/param.h"

SC_MODULE(Master)
{
  sc_in<bool> stimulus_in; //just for simulation
  sc_port<Adapter<sc_int<DATA_BITS>>> data;

  SC_CTOR(Master)
  {
    SC_THREAD(generate);
  }

  void generate(void);
};
#endif
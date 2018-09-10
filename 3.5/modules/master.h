#ifndef MASTER_H
#define MASTER_H

#include <systemc.h>

#include "adapter.h"
#include "../util/param.h"

SC_MODULE(Master)
{
  sc_in<bool> stimulus_in; //just for simulation
  Adapter<sc_int<DATA_BITS>> *data;
 
  SC_CTOR(Master)
  {
    data = new Adapter<sc_int<DATA_BITS>>("adapter");
    SC_THREAD(generate);
  }

  void generate(void);
};
#endif
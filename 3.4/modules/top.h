#ifndef TOP_H
#define TOP_H

#include <systemc.h>

#include "../util/param.h"
#include "master.h"
#include "slave.h"
#include "monitor.h"

SC_MODULE(Top)
{
  sc_clock clk;
  sc_signal<bool> valid, ready;
  sc_signal<sc_int<ERROR_BITS>> error;
  sc_signal<sc_int<DATA_BITS>> data;
  sc_signal<sc_int<CHANNEL_BITS>> channels[MAX_CHANNEL];

  Master *master;
  Slave *slave;
  Monitor *monitor;

  SC_CTOR(Top) : clk("clock", sc_time(CLK_PERIOD, SC_NS))
  {
    monitor = new Monitor("monitor");
    master = new Master("master");
    slave = new Slave("slave");

    master->clk(clk);
    master->valid(valid);
    master->ready(ready);
    master->error(error);
    master->data(data);
    for (int i = 0; i < MAX_CHANNEL; i++)
      master->out_ch(channels[i]);

    slave->clk(clk);
    slave->valid(valid);
    slave->ready(ready);
    slave->error(error);
    slave->data(data);
    for (int i = 0; i < MAX_CHANNEL; i++)
      slave->in_ch(channels[i]);

    monitor->clk(clk);
    monitor->valid(valid);
    monitor->ready(ready);
    monitor->error(error);
    monitor->data(data);
    for (int i = 0; i < MAX_CHANNEL; i++)
      monitor->in_ch(channels[i]);
  }
};

#endif

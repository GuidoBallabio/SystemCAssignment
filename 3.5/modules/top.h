#ifndef TOP_H
#define TOP_H

#include <systemc.h>

#include "../util/param.h"
#include "adapter.h"
#include "master.h"
#include "slave.h"
#include "monitor.h"
#include "stimulus.h"

SC_MODULE(Top)
{
  sc_clock clk;
  sc_signal<bool> valid, ready, reset, stimulus_ch; //stimulus channel for simulation purposes
  sc_signal<sc_int<ERROR_BITS>> error;
  sc_signal<sc_int<DATA_BITS>> data;
  sc_signal<sc_int<CHANNEL_BITS>> channels[MAX_CHANNEL];
  
  
  Adapter<sc_int<DATA_BITS>> *adapter;
  Master *master;
  Slave *slave;
  Monitor *monitor;
  Stimulus * stimulus;

  SC_CTOR(Top) : clk("clock", sc_time(CLK_PERIOD, SC_NS))
  {
    stimulus = new Stimulus("stimulus");
    monitor = new Monitor("monitor");
    adapter = new Adapter<sc_int<DATA_BITS>>("adapter");
    master = new Master("master");
    slave = new Slave("slave");

    master->data(*adapter);
    master->data->clk(clk);
    master->data->valid(valid);
    master->data->reset(reset);
    master->data->ready(ready);
    master->data->error(error);
    master->data->data(data);
    for (int i = 0; i < MAX_CHANNEL; i++)
      master->data->out_ch(channels[i]);

    master->stimulus_in(stimulus_ch);

    slave->clk(clk);
    slave->valid(valid);
    slave->reset(reset);
    slave->ready(ready);
    slave->error(error);
    slave->data(data);
    for (int i = 0; i < MAX_CHANNEL; i++)
      slave->in_ch(channels[i]);

    stimulus->clk(clk);
    stimulus->reset(reset);
    stimulus->stimulus_out(stimulus_ch);  

    monitor->clk(clk);
    monitor->valid(valid);
    monitor->reset(reset);
    monitor->ready(ready);
    monitor->error(error);
    monitor->data(data);
    for (int i = 0; i < MAX_CHANNEL; i++)
      monitor->in_ch(channels[i]);
    monitor->stimulus_in(stimulus_ch);
  }
};

#endif

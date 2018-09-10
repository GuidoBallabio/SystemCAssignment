#ifndef ADAPTER_H
#define ADAPTER_H

#include <systemc.h>

#include "../util/param.h"

template <class T>
class Adapter : public sc_fifo_out_if<T>, public sc_module
{
public:
  sc_in<bool> clk, ready, reset;
  sc_out<bool> valid;
  sc_out<sc_int<DATA_BITS>> data;
  sc_out<sc_int<ERROR_BITS>> error;
  sc_port<sc_signal_out_if<sc_int<CHANNEL_BITS>>, 0> out_ch;

  Adapter(sc_module_name name_) : sc_module(name_) {}

  void write(const T &value)
  {
    while (true)
    {
      if (reset == false)
      {
        cout << "in" << endl;

        wait(ready.posedge_event());
        wait(CLK_PERIOD * (READY_LATENCY - 1), SC_NS);
        wait(clk.posedge_event());
        cout << "write" << endl;

        valid->write(true);
        data->write(value % (1 << DATA_BITS));
        wait(clk.posedge_event());
        valid->write(false);
      }
      else
        wait(clk.posedge_event());
    }
  }

private:
  bool nb_write(const T &data)
  {
    SC_REPORT_FATAL("/Adapter", "Called nb_write()");
    return false;
  }
  virtual int num_free() const
  {
    SC_REPORT_FATAL("/Adapter", "Called num_free()");
    return 0;
  }
  virtual const sc_event &data_read_event() const
  {
    SC_REPORT_FATAL("/Adapter", "Called data_read_event()");
    return *new sc_event;
  }
};
#endif
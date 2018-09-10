#ifndef MONITOR_H
#define MONITOR_H

#include <systemc.h>
#include <iostream>

#include "../util/param.h"

SC_MODULE(Monitor)
{
  sc_in<bool> clk, valid, ready, reset, stimulus_in;
  sc_in<sc_int<DATA_BITS>> data;
  sc_in<sc_int<ERROR_BITS>> error;
  sc_port<sc_signal_in_if<sc_int<CHANNEL_BITS>>, 0> in_ch;

  sc_trace_file *file_handler;

  SC_CTOR(Monitor)
  {
    SC_METHOD(printClk);
    sensitive << clk.pos();

    SC_METHOD(printValid);
    sensitive << valid;

    SC_METHOD(printReady);
    sensitive << ready;

    SC_METHOD(printReset);
    sensitive << reset;

    SC_METHOD(printData);
    sensitive << data;

    SC_METHOD(printError);
    sensitive << error;

    SC_METHOD(printChannels);
    sensitive << in_ch;

    SC_METHOD(printStimulus);
    sensitive << stimulus_in;
  }

  void printClk();
  void printValid();
  void printReady();
  void printReset();
  void printData();
  void printError();
  void printStimulus();
  void printChannels();

  void start_of_simulation(); // for vcd trace file
  void end_of_simulation();
};

#endif

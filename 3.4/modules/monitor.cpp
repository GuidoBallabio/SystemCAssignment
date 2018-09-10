#include "monitor.h"

void Monitor::printClk(){
  std::cout << "clk: " << clk << std::endl;
}

void Monitor::printValid(){
  std::cout << "valid: " << valid << std::endl;
}

void Monitor::printReady(){
  std::cout << "ready: " << ready << std::endl;
}

void Monitor::printData(){
  std::cout << "data: " << data << std::endl;
}

void Monitor::printError(){
  std::cout << "error: " << error << std::endl;
}

void Monitor::printChannels(){
  for (int i=0; i < in_ch.size(); i++)
    std::cout << "ch[" << i << "]: " << in_ch[i] << std::endl;
}

void Monitor::start_of_simulation(){
  file_handler = sc_create_vcd_trace_file("signals");
  file_handler->set_time_unit(1, SC_NS);

  sc_trace(file_handler, clk, "clk");
  sc_trace(file_handler, valid, "valid");
  sc_trace(file_handler, ready, "ready");
  sc_trace(file_handler, data, "data");
  sc_trace(file_handler, error, "error");
  sc_trace(file_handler, clk, "clk");
}

void Monitor::end_of_simulation(){
  sc_close_vcd_trace_file(file_handler);
}
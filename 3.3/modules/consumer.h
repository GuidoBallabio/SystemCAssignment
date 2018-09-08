#ifndef CONSUMER_H
#define CONSUMER_H

#include <systemc.h>

#include "tcp_header.h"

SC_MODULE(Consumer)
{

  sc_fifo_in<TCPHeader> in;

  SC_CTOR(Consumer)
  {
    SC_THREAD(consume_packets);
  }

  void consume_packets(void);
};

void Consumer::consume_packets()
{
  while (true)
  {
    int i = in.read().SequenceNumber;
    cout << i << " at " << sc_time_stamp() << endl;
  }
}
#endif
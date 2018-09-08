#ifndef PRODUCER_H
#define PRODUCER_H

#include <systemc.h>
#include <random>

#include "tcp_header.h"

SC_MODULE(Producer)
{

  sc_fifo_out<TCPHeader> out;

  SC_CTOR(Producer)
  {
    SC_THREAD(generate_packets);
  }

  void generate_packets(void);
};

void Producer::generate_packets()
{
  std::random_device r;
  std::default_random_engine e1(r());
  std::uniform_real_distribution<double> uniform(2, 10);
  TCPHeader packet;

  for (int i = 0; true; i++)
  {
    wait(uniform(e1), SC_MS);
    packet.SequenceNumber = i;
    out.write(packet);
  }
}

#endif
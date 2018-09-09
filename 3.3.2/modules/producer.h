#ifndef PRODUCER_H
#define PRODUCER_H

#include <systemc.h>
#include <random>

#include "tcp_header.h"

SC_MODULE(Producer)
{

  sc_port<sc_fifo_out_if<TCPHeader>,0> out;

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

  for (int i = 0; ; i++)
  {
    wait(uniform(e1), SC_MS);
    packet.SequenceNumber = i;
    for (int i = 0; i < out.size(); i++)
    {
      out[i]->write(packet);
    }
  }
}

#endif
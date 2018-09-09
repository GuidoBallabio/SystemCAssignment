#include "modules/producer.h"
#include "modules/consumer.h"
#include "modules/tcp_header.h"

int sc_main(int argc, char *argv[])
{
  sc_fifo<TCPHeader> ch0("ch0");
  sc_fifo<TCPHeader> ch1("ch1");

  Producer producer("producer");
  Consumer consumer0("consumer0");
  Consumer consumer1("consumer1");

  producer.out(ch0);
  producer.out(ch1);
  consumer0.in(ch0);
  consumer1.in(ch1);


  sc_start(200, SC_MS);
  return 0;
}
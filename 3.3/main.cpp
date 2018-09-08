#include "modules/producer.h"
#include "modules/consumer.h"
#include "modules/tcp_header.h"

int sc_main(int argc, char *argv[])
{
  sc_fifo<TCPHeader> ch("ch");

  Producer producer("producer");
  Consumer consumer("consumer");

  producer.out(ch);
  consumer.in(ch);


  sc_start(200, SC_MS);
  return 0;
}
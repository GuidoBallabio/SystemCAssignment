#include "modules/top.h"

int sc_main(int argc, char *argv[])
{
  Top top("top");
  sc_start(CLK_PERIOD * 200, SC_NS);
  return 0;
}
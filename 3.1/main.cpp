#include "modules/module_single.h"

int sc_main(int argc, char *argv[])
{
  ModuleSingle module_signle("module_single");
  sc_start(200, SC_MS);
  return 0;
}
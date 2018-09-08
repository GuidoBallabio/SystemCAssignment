#include "modules/module_double.h"

int sc_main(int argc, char *argv[])
{
  ModuleDouble module_double("module_double");
  sc_start(200, SC_MS);
  return 0;
}
#include "master.h"
#include "../util/tools.h"

void Master::generate()
{
    while (true)
    {
        int i = 0;
        while (stimulus_in)
        {
            wait(CLK_PERIOD * (random_int() % 5), SC_NS); //max wait = 5 clk
            data->write(i++);
        }
        wait(CLK_PERIOD, SC_NS);
    }
}

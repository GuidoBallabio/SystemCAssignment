#include "master.h"

void Master::generate()
{
    while (true)
    {
        int i = 0;
        while (stimulus_in)
        {
            data->write(i++);
        }
        wait(CLK_PERIOD, SC_NS);
    }
}

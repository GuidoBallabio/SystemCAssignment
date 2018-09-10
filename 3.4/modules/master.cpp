#include "master.h"
#include "../util/tools.h"

void Master::generate()
{
    while (true)
    {
        wait(ready);
        wait(CLK_PERIOD * READY_LATENCY);

        for (uint i = 0; ready->read() && (i < (random_int() % 4)); i++) // 4 is just a small number to make smaller bursts for ease of debuggability
        {
            wait(clk.posedge());
            valid->write(true);
            data->write(random_int() % (1 << DATA_BITS));
        }
    }
}


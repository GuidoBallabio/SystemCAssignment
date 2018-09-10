#include "master.h"
#include "../util/tools.h"

void Master::generate()
{
    while (true)
    {
        while (ready == false)
            wait(clk.posedge_event());

        wait(CLK_PERIOD * (READY_LATENCY), SC_NS);

        for (int i = 0; ready && !reset && stimulus_in; i++) //stimulus just for simulation
        {
            valid->write(true);
            data->write(i % (1 << DATA_BITS));
            wait(clk.posedge_event());
        }

        valid->write(false);
    }
}

#include "master.h"
#include "../util/tools.h"

void Master::generate()
{
    while (true)
    {
        while (ready == false)
            wait(clk.posedge_event());

        for (int i = 0; (i < READY_LATENCY - 1) && !reset; i++)
            wait(clk.posedge_event());

        if (reset || !stimulus_in)
        {
            wait(clk.posedge_event());
            continue;
        }

        for (int i = 0; ready && !reset && stimulus_in; i++) //stimulus just for simulation
        {
            valid->write(true);
            error->write(0);
            for (int j = 0; j < out_ch.size(); j++)
                out_ch[j]->write(0);
            data->write(i % (1 << DATA_BITS));
            wait(clk.posedge_event());
        }

        valid->write(false);
    }
}

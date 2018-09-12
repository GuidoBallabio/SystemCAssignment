#include <iostream>

#include "slave.h"

void Slave::consume()
{
    ofstream f;
    f.open("consumed.txt");

    while (true)
    {
        if (reset == false)
        {
            ready->write(true);
            for (int i = 0; i < READY_LATENCY && !reset; i++)
                wait(clk.posedge_event());

            while (valid == false && !reset)
                wait(clk.posedge_event());

            while (valid == true && !reset)
            {
                f << data->read() << " received at simulation time " << sc_time_stamp() << endl;
                in_ch->read();
                // Simulate error handling
                int errorno = error->read();
                if (errorno != 0)
                {
                    f << "Error occured with code ERRNO " << error << " at simulation time " << sc_time_stamp() << endl;
                }

                wait(clk.posedge_event());
            }
        }
        else
        {
            ready->write(false);
            wait(clk.posedge_event());
        }
    }

    f.close();
}
#include <iostream>

#include "slave.h"

void Slave::consume()
{
    ofstream f;
    f.open("consumed.txt");

    while (true)
    {
        if (reset == true)
        {
            ready->write(false);
        }

        wait(clk.posedge_event());
        ready->write(true);
        for (int i = 0; i < READY_LATENCY && !reset; i++)
            wait(clk.posedge_event());

        while(valid == false && !reset)
            wait(clk.posedge_event());

        cout << "before read: " << valid << " " << reset << endl;
        while (valid == true && !reset){
            f << data->read() << endl;
            wait(clk.posedge_event());
        }
    }

    f.close();
}
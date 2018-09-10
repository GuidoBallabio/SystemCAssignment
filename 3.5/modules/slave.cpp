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

            cout << "wait valid" << endl;

            while (valid == false && !reset)
                wait(clk.posedge_event());
            cout << "read" << endl;

            while (valid == true && !reset)
            {
                f << data->read() << endl;
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
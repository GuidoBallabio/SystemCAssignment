#include <iostream>

#include "slave.h"
#include "../util/tools.h"

void Slave::consume()
{
    ofstream f;
    f.open("consumed.txt");
    
    while (true)
    {
        wait(clk.posedge());

        ready->write(true);
        while (valid->read() && ((random_int() % 4) < 3)) //ready 3/4 of the time
        {
            wait(clk.posedge());
            f << data->read() << endl;
        }
        ready->write(false);
    }

    f.close();
}
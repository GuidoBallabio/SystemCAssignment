#include "slave.h"
#include "../util/tools.h"

void Slave::consume()
{
    while (true)
    {
        wait(clk.posedge());

        ready->write(true);
        while (valid->read() && ((random_int() % 4) < 3)) //ready 3/4 of the time
        {
            wait(clk.posedge());
            data->read();
        }
        ready->write(false);
    }
}
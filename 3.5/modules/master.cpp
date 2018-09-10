#include "master.h"
#include "../util/tools.h"

void Master::generate()
{
    while (true)
    {
        int i = 0;
        while (stimulus_in)
        {
            cout << "easy" << endl;

            wait(CLK_PERIOD * (random_int() % 10), SC_NS);
            cout << "b";
            data->write(i++);
            cout << "a";
        }
    }
}

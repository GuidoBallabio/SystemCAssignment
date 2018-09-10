#include "tools.h"

uint64 random_int()
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<uint64> uniform;

    return uniform(e1);
}
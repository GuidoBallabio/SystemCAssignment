#include "tools.h"

uint64 random_int()
{
    static std::random_device r;
    static std::default_random_engine e1(r());
    static std::uniform_int_distribution<uint64> uniform;

    return uniform(e1);
}
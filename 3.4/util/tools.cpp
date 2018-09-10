#include "tools.h"

std::random_device r;
std::default_random_engine engine(r());
std::uniform_int_distribution<uint64_t> uniform;


uint64_t random_int()
{
    return uniform(engine);
}

// random boolean with p probability of being true
bool random_bool(double p)
{
    std::bernoulli_distribution b(p);
    return b(engine);
}
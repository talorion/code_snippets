#include "three_int_hash.hpp"


static const int P1=997;        //should be prime
static const int P2=1009;       //should be prime

int generate_hash(int a, int b, int c)
{
    int h = (a*P1 + b)*P2 + c;

    return h;
}

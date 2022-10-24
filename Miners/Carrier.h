#include "IMiner.h"

#ifndef CARRIER

#define CARRIER 1

using namespace std;

class Carrier : public IMiner
{
public:
    Carrier(Mina *Pmina) : IMiner(Pmina)
    {
        this->Mname = "Carrier";
        this->speed = 10;
        this->cap = 40;
    }

};

#endif
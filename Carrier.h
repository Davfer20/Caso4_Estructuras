#include "IMiner.h"

#ifndef CARRIER

#define CARRIER 1

using namespace std;

class Carrier : public IMiner
{
public:
    Carrier(vector<IStrat> pmStrat, Mina *Pmina) : IMiner(pmStrat, Pmina)
    {
        this->Mname = "Carrier";
        this->speed = 10;
        this->cap = 40;
    }

    void mining() 
    {
    }
};

#endif
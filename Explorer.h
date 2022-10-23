#include "IMiner.h"

#ifndef EXPLO

#define EXPLO 1

using namespace std;

class Explorer : public IMiner
{
public:
    Explorer(vector<IStrat> pmStrat, Mina *Pmina) : IMiner(pmStrat, Pmina)
    {
        this->Mname = "Explorer";
        this->speed = 20;
        this->cap = 8;
    }

};

#endif
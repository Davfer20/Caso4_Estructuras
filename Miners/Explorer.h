#include "IMiner.h"

#ifndef EXPLO

#define EXPLO 1

using namespace std;

class Explorer : public IMiner
{
public:
    Explorer(Mina *Pmina) : IMiner(Pmina)
    {
        this->Mname = "Explorer";
        this->speed = 20;
        this->cap = 8;
    }

};

#endif
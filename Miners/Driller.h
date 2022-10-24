#include "IMiner.h"

#ifndef DRILLER

#define DRILLER 1

using namespace std;

class Driller : public IMiner
{
private:
    bool ability;

public:
    Driller(Mina *Pmina) : IMiner(Pmina)
    {
        this->Mname = "Driller";
        this->speed = 7;
        this->cap = 15;
        this->ability = true;
    }

    void mining() 
    {
    }
};

#endif

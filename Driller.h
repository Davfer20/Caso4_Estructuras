#include "IMiner.h"

#ifndef DRILLER

#define DRILLER 1

using namespace std;

class Driller : public IMiner
{
private:
    bool ability;

public:
    Driller(vector<IStrat> pmStrat, Mina *Pmina) : IMiner(pmStrat, Pmina)
    {
        this->Mname = "Driller";
        this->speed = 7;
        this->cap = 15;
        this->ability = true;
    }

    void mining() override
    {
    }
};

#endif

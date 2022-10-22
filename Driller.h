#include "IMiner.h"
#include "Sala.h"
#include "Mina.h"
#include "List.h"
#include <string.h>
#include <iostream>

#ifndef DRILLER

#define DRILLER 1

using namespace std;

class Driller : public IMiner
{
private:
    bool ability;

public:
    Driller(int PmStrat, Mina *Pmina) : IMiner(PmStrat, Pmina)
    {
        this->Mname = "Driller";
        this->speed = 7;
        this->cap = 15;
        this->ability = true;
    }

    void mining() override {
        
    }
};

#endif DRILLER

#include "Sala.h"
#include "Mina.h"
#include "List.h"
#include <string.h>
#include <thread>
#include <iostream>

#ifndef IMINER

#define IMINER 1

using namespace std;

struct timespec sec1 = {1, 0}; // Pausa de un segundo

class IMiner
{
protected:
    Sala *currentSala;
    vector<int> disPaths;
    string action;
    string Mname;
    Mina *currentMina;
    int Mstrat;
    int inventory;
    int cap;
    int speed;
    int lastDir;
    int state; // 0 sala, 1 tunel
public:
    IMiner(int PmStrat, Mina* Pmina) {
        this->currentMina = Pmina;
        this->currentSala = Pmina->getSalasList()->find(0);
        this->inventory = 0;
        this->Mstrat = PmStrat;
    }
    string getMname()
    {
        return this->Mname;
    }

    string getAction()
    {
        return this->action;
    }

    int getInventory()
    {
        return this->inventory;
    }

    int getState()
    {
        return this->state;
    }

    Sala *getSala()
    {
        return this->currentSala;
    }

    virtual void mining() = 0;
};

#endif
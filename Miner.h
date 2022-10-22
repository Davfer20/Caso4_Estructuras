#include "Sala.h"
#include "Mina.h"
#include "List.h"
#include <string.h>
#include <thread>
#include <iostream>

#ifndef MINER

#define MINER 1

using namespace std;

struct timespec sec1 = {1, 0}; // Pausa de un segundo

class Miner
{
private:
    Sala *currentSala;
    vector<int> disPaths;
    string action;
    string Mname;
    Mina *currentMina;
    int Mtype; // 0 - Explorer, 1 - Carrier, 2 - Driller
    int Mstrat;
    int inventory;
    int cap;
    int speed;
    int lastDir;
    int state; // 0 sala, 1 tunel

public:
    Miner(int PmType, int PmStrat, Mina *Pmina)
    {
        this->currentMina = Pmina;
        this->currentSala = Pmina->getSalasList()->find(0);
        this->inventory = 0;
        this->Mstrat = PmStrat;
        switch (PmType)
        {
        case 0:
            this->Mtype = 0;
            this->Mname = "Explorer";
            this->speed = 20;
            this->cap = 8;
            break;
        case 1:
            this->Mtype = 1;
            this->Mname = "Carrier";
            this->speed = 10;
            this->cap = 40;
            break;

        default:
            this->Mtype = 2;
            this->Mname = "Driller";
            this->speed = 7;
            this->cap = 15;
            break;
        }
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

    void mining()
    {
        if (!state)
        {
            this->action = "Explorando la sala " + to_string(currentSala->getID());
            if (currentSala->getIfTunel() && !(rand() % 3))
            {
                this->action = "Explorando el tunel " + to_string(currentSala->getID());
                this->state = 1;
            }
            else
            {
                disPaths = currentSala->availablePaths();
                int rDire;
                int max = disPaths.size();
                rDire = rand();
                rDire %= max;
                rDire = disPaths[rDire];
                this->currentSala = currentSala->getSalaDir(rDire);
            }
        } else if (state == 1)
        {
            // logica de los tuneles
            // Recorrer
            // Strat - al volver a la camara buscar otra?
            // Extraer 
            // Inhabilitar
        }
        
    }
};

#endif

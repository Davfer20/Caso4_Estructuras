#include "OfficialMain\Sala.h"
#include "OfficialMain\Mina.h"
#include "Generics\NodeAVL.h"
#include "Generics\List.h"
#include "Global\Singleton.h"
#include "OfficialMain\Chamber.h"
#include <string>
#include <iostream>
#include "IStrat.h"

#ifndef IMINER

#define IMINER 1

using namespace std;

// Clase miner propensa a ser inutilizada
class IMiner
{
protected:
    string Mname;
    Sala *currentSala;
    NodeAVL<Chamber> *currentChamberNode;
    Chamber *currentChamber;
    vector<int> disPaths;
    string action;
    Mina *currentMina;
    vector<IStrat> mStrat;
    int inventory;
    int cap;
    int speed;
    int state; // 0 sala, 1 tunel, 2 descarga
    int deepdis;
    int cooldown;

public:
    IMiner(vector<IStrat> pmStrat, Mina *Pmina)
    {
        this->currentMina = Pmina;
        this->currentSala = Pmina->getSalasList()->find(0);
        this->inventory = 0;
        this->mStrat = pmStrat;
        this->state = 0;
        this->cooldown = 0;
        this->currentChamber = NULL;

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

    int getCap()
    {
        return this->cap;
    }

    Sala *getSala()
    {
        return this->currentSala;
    }

    void exploring() // State 0
    {
        this->action = "Explorando la sala " + to_string(currentSala->getID());
        if (currentSala->getIfTunel() && !(rand() % 3))
        {
            this->state = 1;
            this->currentChamberNode = currentSala->getTunel()->getNodeRaiz();
            this->deepdis = 0;
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
    }
    virtual void mining() // State 1
    {
    }

    void unloading() // State 2
    {
        if (cooldown != 0)
        {
            cooldown -= 1;
            return;
        }

        this->action = "Descargando inventario " + to_string(currentSala->getID());
        Singleton *var = var->getInstance();
        var->addLoad(this->inventory);
        this->inventory = 0;

        this->state = 1;
        if (rand() % 2)
        {
            this->currentChamber = NULL;
            this->state = 0;
        }
    }

    void death() // State 3 x_x
    {
    }

    string getMrlCurrentChamb()
    { // 20/14
        string resul = "Ø";
        if (this->currentChamber != NULL)
        {
            resul = this->currentChamber->getMaterial();
        }
        return resul;
    }
};

#endif
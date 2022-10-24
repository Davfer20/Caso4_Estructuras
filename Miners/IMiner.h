#include "..\OfficialMain\Sala.h"
#include "..\OfficialMain\Mina.h"
#include "..\OfficialMain\Chamber.h"
#include "..\Generics\NodeAVL.h"
#include "..\Generics\List.h"
#include "..\Global\Singleton.h"
#include "..\Strats\IStrat.h"
#include <string>
#include <iostream>

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
    IStrat *mStrat;

    int inventory;
    int cap;
    int speed;
    int state; // 0 sala, 1 tunel, 2 descarga
    int deepdis;
    int cooldown;

public:
    IMiner(Mina *Pmina)
    {
        this->currentMina = Pmina;
        this->currentSala = Pmina->getSalasList()->find(0);
        this->inventory = 0;
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

    void setStrat(IStrat *pStrat)
    {
        this->mStrat = pStrat;
    }
    string getStrat()
    {
        return this->mStrat->getName();
    }

    void exploring() // State 0
    {
        this->action = "Explorando la sala " + to_string(currentSala->getID());
        if (currentSala->getIfTunel())
        {
            this->currentChamberNode = currentSala->getTunel()->getNodeRaiz();
            if (mStrat->enterTunel(currentChamberNode))
            {
                this->state = 1;
                this->deepdis = 0;
                return;
            }
        }
        disPaths = currentSala->availablePaths();
        this->currentSala = currentSala->getSalaDir(mStrat->chooseSala(disPaths));
    }

    void mining() // State 0
    {
        if (cooldown != 0)
        {
            cooldown -= 1;
            return;
        }

        currentChamber = currentChamberNode->content;
        this->deepdis += currentChamber->getDistance();
        currentSala->getTunel()->getChambers()->countSearh(currentChamber->getPot(), currentSala->getTunel()->getNodeRaiz());
        int deep = currentSala->getTunel()->getChambers()->getCount();
        int distance;

        this->action = "Explorando el tunel " + to_string(currentSala->getID()) + ", prufundidad: " + to_string(deep);
        if (deep == 1 || !mStrat->mineOrgGodeep(deep)) // Posibilidad de seguir adentrandose
        {

            int paths = 0;
            if (currentChamberNode->derecho != NULL)
            {
                paths += currentChamberNode->derecho->content->ifValid() ? 1 : 0;
            }
            if (currentChamberNode->izquierdo != NULL)
            {
                paths += currentChamberNode->izquierdo->content->ifValid() ? 2 : 0;
            }

            if (!paths)
            { // Devolverse al inicio si ya no hay camino
                distance = deepdis;
                deepdis = 0;
                this->state = 2;
            }
            else
            {
                int path = mStrat->choosePath(paths);
                currentChamberNode = path ? currentChamberNode->izquierdo : currentChamberNode->derecho;
                distance = currentChamberNode->content->getDistance();
                deepdis += distance;
            }
            cooldown = distance / this->speed;
            currentChamber = currentChamberNode->content;
        }
        else
        {
            while (inventory != cap && currentChamber->ifValid())
            {
                this->inventory += currentChamber->pickMineral();
            }
            distance = deepdis;
            deepdis = 0;

            cooldown = distance / this->speed;
            cooldown /= 2;

            this->state = 2;
            currentChamber = currentChamberNode->content;
        }
    }

    void gettingBack() // State 2
    {
        death();
        this->currentChamber = NULL;
        this->currentChamberNode = currentSala->getTunel()->getNodeRaiz();

        this->action = "Volviendo a la sala con material...";
        if (cooldown != 0)
        {
            cooldown -= 1;
            return;
        }
        this->state = 3;
        deepdis = 0;
    }
    void unloading() // State 3
    {

        this->action = "Descargando inventario " + to_string(currentSala->getID());
        Singleton *var = var->getInstance();
        var->addLoad(this->inventory);
        this->inventory = 0;

        this->state = 0;
        if (mStrat->enterTunel(currentChamberNode))
        {
            this->state = 1;
        }
    }

    void death() // State 4 x_x
    {
        if (currentSala->getTunel()->getChambers()->searhPath(currentChamberNode->dato, currentSala->getTunel()->getNodeRaiz()) == NULL)
        {
            this->action = "Ha muerto; 2022 - 2022";
            this->state = 4;
        }
    }
};
#endif
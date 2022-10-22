#include "Sala.h"
#include "Mina.h"
#include "NodeAVL.h"
#include "List.h"
#include "Singleton.h"
#include "Chamber.h"
#include <string.h>
#include <iostream>

#ifndef MINER

#define MINER 1

using namespace std;

struct timespec sec1 = {1, 0}; // Pausa de un segundo

class Miner
{
private:
    Sala *currentSala;
    NodeAVL<Chamber> *currentChamberNode;
    Chamber* currentChamber;
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
    int deepdis;
    int cooldown;

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

    void exploring()  // State 0
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
    void mining() // State 1
    {
        if (!cooldown)
        {
            cooldown -= 1;
            return;
        }
        //Singleton *var = var->getInstance();
        //var->addLoad(5);
        currentChamber = currentChamberNode->content;
        this->deepdis += currentChamber->getDistance();
        this->action = "Explorando el tunel " + to_string(currentSala->getID()) + to_string(currentChamber->getDeep());
        if (currentChamber->getDeep() == 1 || rand() % 2) // Posibilidad de seguir adentrandose 
        {
            int distance;
            int path = rand() % 2;
            if ((currentChamberNode->derecho != NULL || currentChamberNode->derecho->content->ifValid()) && path)
            {
                currentChamberNode = currentChamberNode->derecho;
                distance = currentChamber->getDistance();
            } else if ((currentChamberNode->izquierdo != NULL || currentChamberNode->derecho->content->ifValid()) && !path)
            {
                currentChamberNode = currentChamberNode->izquierdo;
                distance = currentChamber->getDistance();
            } else { // Devolverse al inicio si ya no hay camino
                this->currentChamberNode = currentSala->getTunel()->getNodeRaiz();
                distance = deepdis;
                deepdis = 0;
                this->action = "Volviendo a la sala...";
            }
            currentChamber = currentChamberNode->content;
            cooldown = distance / this->speed; 

        } // mina
        
    }

    void unloading() // State 2
    {
        this->action = "Descargando inventario " + to_string(currentSala->getID());
        Singleton *var = var->getInstance();
        var->addLoad(this->inventory);
        this->inventory = 0;

        this->state = 0;
        if (rand() % 2)
        {
            this->state = 1;
        }
    }

    void death() // State 3 x_x
    {
    }
};

#endif

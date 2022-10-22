#include "Tunel.h"
#include "List.h"
#include "Singleton.h"
#include <iostream>
#include <vector>


#ifndef SALA

#define SALA 1

using namespace std;

Singleton *Singleton::instance = 0;

class Sala
{
private:
    bool ifTunel; // Guarda si hay tunel
    bool done;    // Guarda si ya se le agregaron salas
    int ID;
    Tunel *tunel;
    Sala *north; // 0
    Sala *south; // 1
    Sala *west; // 2
    Sala *east; // 3

public:
    Sala()
    {
        this->ifTunel = false;
        this->south = this->north = this->east = this->west = NULL;
        this->ID = 0;
    }

    Sala(Sala *adya, int dire, bool pifTunel) // Punteros con sala y tunel
        {
        this->south = this->north = this->east = this->west = NULL;
        Singleton *var = var->getInstance();
        this->ID = var->getData();
        var->IncData();
        switch (dire) {
        case 0:
            this->south = adya;
            adya->setNorth(this);
            break;

        case 1:
            this->north = adya;
            adya->setSouth(this);
            break;

        case 3:
            this->west = adya;
            adya->setEast(this);
            break;

        default:
            this->east = adya;
            adya->setWest(this);
            break;
        };

        if (!pifTunel) {
            this->ifTunel = false;
        } else {
            this->ifTunel = true;
            this->tunel = new Tunel(this->ID);   
        }
    }


    void setSouth(Sala *pSala)
    {
        this->south = pSala;
    }

    void setNorth(Sala *pSala)
    {
        this->north = pSala;
    }

    void setEast(Sala *pSala)
    {
        this->east = pSala;
    }

    void setWest(Sala *pSala)
    {
        this->west = pSala;
    }

    void setDone()
    {
        this->done = true;
    }

    bool getIfTunel()
    {
        return this->ifTunel;
    }

    Tunel* getTunel()
    {
        return this->tunel;
    }

    Sala* getSalaDir(int pDir) {
        Sala* resul;
        switch (pDir)
        {
        case 0:
            resul = north;
            break;

        case 1:
            resul = south;
            break;

        case 3:
            resul = east;
            break;
        default:
            resul = west;
            break;
        }
        return resul;
    }

    int getID() {
        return this->ID;
    }


    bool getDone()
    {
        return done;
    }

    vector<int> available()
    { 
        vector<int> availablesN;

        if (this->north == NULL)
        {
            availablesN.push_back(0);
        }
        if (this->south == NULL)
        {
            availablesN.push_back(1);
        }
        if (this->west == NULL)
        {
            availablesN.push_back(2);
        }
        if (this->east == NULL)
        {
            availablesN.push_back(3);
        }
        return availablesN;
    }

    vector<int> availablePaths()
    { // [1,0,1,0]
        vector<int> availablesN;

        if (this->north != NULL)
        {
            availablesN.push_back(0);
        }
        if (this->south != NULL)
        {
            availablesN.push_back(1);
        }
        if (this->west != NULL)
        {
            availablesN.push_back(2);
        }
        if (this->east != NULL)
        {
            availablesN.push_back(3);
        }
        return availablesN;
    }
};

#endif
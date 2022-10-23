#include "Tunel.h"
#include "..\Generics\List.h"
#include "..\Global\Singleton.h"
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
    Tunel *tunel; // * Tunel asociado a la Sala
    bool done;    // Guarda si ya se le agregaron salas
    int ID;
    Sala *north; // 0
    Sala *south; // 1
    Sala *west;  // 2
    Sala *east;  // 3

public:
    // Contructor de Sala con adyacencias en NULL
    Sala()
    {
        this->ifTunel = false;
        this->south = this->north = this->east = this->west = NULL;
        this->ID = 0;
    }

    // Contructor de Sala con adyacencia a otra Sala
    Sala(Sala *adya, int dire, bool pifTunel)
    {
        this->south = this->north = this->east = this->west = NULL;
        Singleton *var = var->getInstance();
        this->ID = var->getData();
        var->IncData();

        // Identificacion de la direccion de la adyacencia
        switch (dire)
        {
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

        // Asignacion del tunel
        if (!pifTunel)
        {
            this->ifTunel = false;
        }
        else
        {
            this->ifTunel = true;
            this->tunel = new Tunel(this->ID);
        }
    }

    // Retorna un Ptr a la sala al South
    void setSouth(Sala *pSala)
    {
        this->south = pSala;
    }

    // Retorna un Ptr a la sala al North
    void setNorth(Sala *pSala)
    {
        this->north = pSala;
    }

    // Retorna un Ptr a la sala al East
    void setEast(Sala *pSala)
    {
        this->east = pSala;
    }

    // Retorna un Ptr a la sala al West
    void setWest(Sala *pSala)
    {
        this->west = pSala;
    }

    void setDone()
    {
        this->done = true;
    }

    int getID()
    {
        return this->ID;
    }
    
    bool getDone()
    {
        return done;
    }

    bool getIfTunel()
    {
        return this->ifTunel;
    }

    Tunel *getTunel()
    {
        return this->tunel;
    }

    // Retorna la Sala de la direccion dada en forma de Int
    Sala *getSalaDir(int pDir)
    {
        Sala *resul;
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

    // Retorna un vector de las Adyacencias disponibles para asignar conexion con otra Sala
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

    // Retorna un vector con los posibles caminos que puede tomar el IMiner
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
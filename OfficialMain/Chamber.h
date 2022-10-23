#include <iostream>
#include <string>

#ifndef CHAMB

#define CHAMB 1

using namespace std;

// Clase que contiene informacion de cada recamara del Tunel
class Chamber
{
private:
    int potential;  // Distancia * Mineral
    int distance;   // Distancia al Chamber anterior
    int mineral;    // Mineral actual en el Chamber
    int totMineral; // Mineral generado en el Chamber
    bool valid;     // En caso de vaciarse para a ser invalid

public:
    // Distancia random entre 10 a 80 
    int getRandDistance()
    {
        int resul = rand() % 70 + 10;
        return resul;
    }

    // Cantidad de mineral random entre 1 a 20
    int getRandMineral()
    {
        return rand() % 19 + 1;
    }

    // Generador de Chamber
    Chamber()
    {
        this->distance = getRandDistance();
        this->mineral = getRandMineral();
        this->potential = this->distance * this->mineral;
        this->valid = true;
        this->totMineral = this->mineral;
    }

    // Retorna el potencial
    int getPot()
    {
        return this->potential;
    }

    // Retorna si la sala es valida
    bool ifValid()
    {
        return this->valid;
    }

    int getDistance()
    {
        return this->distance;
    }

    // Decrementa en uno el mineral y verifica si ya quedó invalidado el Chamber
    int pickMineral()
    {
        this->mineral -= 1;
        if (!this->mineral)
        {
            this->valid = false;
        }
        return 1;
    }

    // Retorna informacion del mineral en el Chamber
    string getMaterial()
    {
        return to_string(this->mineral) + "/" + to_string(this->totMineral);
    }
};

#endif
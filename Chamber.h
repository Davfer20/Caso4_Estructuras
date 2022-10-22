#include <iostream>

#ifndef CHAMB

#define CHAMB 1

class Chamber
{
private:
    int potential;
    int distance;
    int mineral;
    int deep;
    bool valid = false;

public:
    // Distancia random entre 10 a 80 pero que el total no supere
    int getRandDistance()
    {
        int resul = rand() % 70 + 10;
        return resul;
    }
    int getRandMineral()
    {
        return rand() % 19 + 1;
    }

    Chamber() // 700
    {
        this->distance = getRandDistance();
        this->mineral = getRandMineral();
        this->potential = this->distance * this->mineral;
        this->valid = true;
    }

    int getPot()
    {
        return this->potential;
    }
    int getDeep()
    {
        return this->deep;
    }
    void setDeep(int pDeep)
    {
        this->deep = pDeep;
    }
};

#endif
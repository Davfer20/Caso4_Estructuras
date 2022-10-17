#include <iostream>

#ifndef CHAMB

#define CHAMB 1

class Chamber
{
private:
    int potential;
    int distance;
    int totDis;
    int mineral;
    int dif; // Altura right - Altura left
    Chamber *left;
    Chamber *right;
    bool valid = false;

public:
    Chamber()
    {
        this->potential = 0;
        this->distance = 0;
        this->distance = 0;
        this->mineral = 0;
        this->dif = 0;
        this->left = NULL;
        this->right = NULL;
    }

    // Distancia random entre 10 a 80 pero que el total no supere
    int getRandDistance(int TotDis)
    {
        int resul = rand() % 70 + 10;
        if (TotDis + resul > 710)
        {
            resul = (rand() % (710 - TotDis)) + 10;

        } else if (TotDis == 720)
        {
            resul = -1;
        }

        return resul;
    }
    int getRandMineral()
    {
        return rand() % 19 + 1;
    }

    Chamber(int pTotDis) // 700
    {
        this->distance = getRandDistance(pTotDis);

        if (this->distance != -1)
        {
            this->valid = true;
        }

        this->totDis = pTotDis + distance;
        this->mineral = getRandMineral();
        this->potential = this->distance * this->mineral;
        this->dif = 0;
        this->left = NULL;
        this->right = NULL;
    }

    int getPot()
    {
        return this->potential;
    }

    int getTotDis()
    {
        return this->totDis;
    }

    Chamber *getLeft()
    {
        return this->left;
    }

    void setLeft(Chamber *Pchamber)
    {
        this->left = Pchamber;
    }

    Chamber *getRight()
    {
        return this->right;
    }

    void setRight(Chamber *Pchamber)
    {
        this->right = Pchamber;
    }

    void setDif(int pDif)
    {
        this->dif = pDif;
    }

    int getDif()
    {
        return this->dif;
    }
};

#endif
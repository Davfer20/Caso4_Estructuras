#include <iostream>

#ifndef CHAMB

#define CHAMB 1

class Chamber
{
private:
    int potential;
    int distance;
    int totdis;
    int mineral;
    int dif; // Altura right - Altura left
    Chamber *left;
    Chamber *right;

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

    int getRandDistance(int TotDis)
    {
        int resul = rand() % 70 + 10;
        if (TotDis + resul > 710)
        {
            resul = (rand() % (710 - TotDis)) + 10;
        }
        return resul;
    }
    int getRandMineral()
    {
        return rand() % 19 + 1;
    }

    Chamber(int pTotDis) // 700
    {
        this->totdis = pTotDis;
        this->distance = getRandDistance(pTotDis);
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

    Chamber* getLeft()
    {
        return this->left;
    }

    void setLeft(Chamber* Pchamber)
    {
        this->left = Pchamber;
    }

    Chamber* getRight()
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
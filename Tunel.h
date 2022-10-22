#include <iostream>
#include "Chamber.h"
#include "AVL.cpp"

#ifndef TUNEL

#define TUNEL 1

using namespace std;

class Tunel
{
private:
    int ID;
    NodeAVL<Chamber> *raiz;
    AVL<Chamber> *chambers;

public:
    Tunel(int pID)
    {
        this->ID = pID;
        this->chambers = new AVL<Chamber>();
        this->raiz = chambers->getRaiz();

        while (chambers->getCount() <= 9)
        {
            Chamber *chamber1 = new Chamber();
            chambers->add(chamber1->getPot(), chamber1);
            chambers->countSearh(chamber1->getPot(), chambers->getRaiz());
            chamber1->setDeep(chambers->getCount());
        }
    }
};

#endif

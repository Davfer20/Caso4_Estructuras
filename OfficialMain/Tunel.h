#include <iostream>
#include "Chamber.h"
#include "..\Generics\AVL.h"

#ifndef TUNEL

#define TUNEL 1

using namespace std;

// Clase que maneja el Sistema de Chambers de la mina mediante un Arbol AVL
class Tunel
{
private:
    int ID;                 // ID = al de la sala
    AVL<Chamber> *chambers; // * Arbol AVL de Chambers
    NodeAVL<Chamber> *raiz; // * NodoAVL raiz

public:
    // Constructor del Tunel, incluye el Arbol AVL
    Tunel(int pID)
    {
        this->ID = pID;
        this->chambers = new AVL<Chamber>();
        // Creacion de un Arbol AVL de Chambers que no sobrepase los 720mts de profundidad
        while (chambers->getCount() <= 9)
        {
            Chamber *chamber1 = new Chamber();
            chambers->add(chamber1->getPot(), chamber1);
            chambers->countSearh(chamber1->getPot(), chambers->getRaiz());
        }
        this->raiz = chambers->getRaiz();
    }

    // Retorna un Ptr al nodoAVL-raiz del arbol
    NodeAVL<Chamber> *getNodeRaiz()
    {
        return this->raiz;
    }

    // Retorna un Ptr al Arbol AVL
    AVL<Chamber> *getChambers()
    {
        return this->chambers;
    }
};

#endif

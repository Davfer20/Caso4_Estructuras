#include <iostream>
#include "Chamber.h"

#ifndef TUNEL

#define TUNEL 1

using namespace std;

class Tunel
{
private:
    Chamber *raiz;

public:
    Tunel()
    {
        this->raiz = NULL;
    }

    // Busca nodo de manera recursiva
    Chamber *find(int potential, Chamber *raiz)
    {
        if (raiz == NULL)
        {
            return NULL;
        }
        else if (raiz->getPot() == potential)
        {
            return raiz;
        }
        else if (raiz->getPot() < potential)
        {
            return find(potential, raiz->getRight());
        }
        else if (raiz->getPot() > potential)
        {
            return find(potential, raiz->getLeft());
        }
    }

    // Obtiene Altura right - Altura left del chamber 
    int obtenerDif(Chamber *chamber)
    {
        if (chamber == NULL)
        {
            return -1;
        }
        else
        {
            return chamber->getDif();
        }
    }

    Chamber *rotacionIzquierda(Chamber *chamber)
    {
        Chamber *aux = chamber->getLeft();
        chamber->setLeft(aux->getRight());

        aux->setRight(chamber);

        //                     altura izquiero                             altura derecho       
        chamber->setDif(max(this->obtenerDif(chamber->getLeft()), this->obtenerDif(chamber->getRight())) + 1);
        aux->setDif(max(this->obtenerDif(aux->getLeft()), this->obtenerDif(aux->getRight())) + 1);

        return aux;
    }

    Chamber *rotacionDerecha(Chamber *chamber)
    {
        Chamber *aux = chamber->getRight();
        chamber->setRight(aux->getLeft());

        aux->setLeft(chamber);

        chamber->setDif(max(this->obtenerDif(chamber->getLeft()), this->obtenerDif(chamber->getRight())) + 1);
        aux->setDif(max(this->obtenerDif(aux->getLeft()), this->obtenerDif(aux->getRight())) + 1);

        return aux;
    }

    Chamber *rotacionDobleIzquierda(Chamber *chamber)
    {
        Chamber *aux;
        chamber->setLeft(this->rotacionDerecha(chamber->getLeft()));
        aux = this->rotacionIzquierda(chamber);

        return aux;
    }

    Chamber *rotacionDobleDerecha(Chamber *chamber)
    {
        Chamber *aux;
        chamber->setRight(this->rotacionIzquierda(chamber->getRight()));
        aux = this->rotacionDerecha(chamber);

        return aux;
    }

    Chamber *addChamber(Chamber *newC, Chamber *subChamber)
    {
        Chamber *newCPadre = subChamber;

        if (newC->getPot() < subChamber->getPot())
        {
            if (subChamber->getLeft() == NULL)
            {
                subChamber->setLeft(newC);
            }
            else
            {
                subChamber->setLeft(this->addChamber(newC, subChamber->getLeft()));

                int balance = this->obtenerDif(subChamber->getLeft()) - this->obtenerDif(subChamber->getRight());

                if (balance == 2)
                {
                    if (newC->getPot() < subChamber->getLeft()->getPot())
                    {
                        newCPadre = this->rotacionIzquierda(subChamber);
                    }
                    else
                    {
                        newCPadre = this->rotacionDobleIzquierda(subChamber);
                    }
                }
            }
        }
        else {
            if (subChamber->getRight() == NULL)
            {
                subChamber->setRight(newC);
            }
            else
            {
                subChamber->setRight(this->addChamber(newC, subChamber->getRight()));

                int balance = this->obtenerDif(subChamber->getRight()) - this->obtenerDif(subChamber->getLeft());

                if (balance == 2)
                {
                    if (newC->getPot() > subChamber->getRight()->getPot())
                    {
                        newCPadre = this->rotacionDerecha(subChamber);
                    }
                    else
                    {
                        newCPadre = this->rotacionDobleDerecha(subChamber);
                    }
                }
            }
        }

        // Actualizando factor de equilibrio
        if ((subChamber->getLeft() == NULL) && (subChamber->getRight() != NULL))
        {
            subChamber->setDif(subChamber->getRight()->getDif() + 1);
        }
        else if ((subChamber->getRight() == NULL) && (subChamber->getLeft() != NULL))
        {
            subChamber->setDif(subChamber->getLeft()->getDif() + 1);
        }
        else
        {
            subChamber->setDif(max(this->obtenerDif(subChamber->getLeft()), this->obtenerDif(subChamber->getRight())) + 1);
        }

        return newCPadre;
    }

    void add(Chamber* chamber)
    {
        Chamber *newC = chamber;

        if (this->raiz == NULL)
        {
            this->raiz = newC;
        }
        else
        {
            this->raiz = this->addChamber(newC, raiz);
        }
    }

    void generateTunel() {
        int maxDis = 720;
        
    }

    Chamber *getRaiz()
    {
        return this->raiz;
    }

    void postOrden(Chamber *chamber)
    {
        if (chamber != NULL)
        {
            this->postOrden(chamber->getLeft());
            this->postOrden(chamber->getRight());
            cout << chamber->getPot() << ", ";
        }
    }

};

#endif

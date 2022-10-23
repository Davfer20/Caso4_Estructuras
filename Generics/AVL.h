#include "NodeAVL.h"
#include <iostream>

using namespace std;

#ifndef AVl

#define AVl 1

template <typename T>
class AVL
{
private:
    NodeAVL<T> *raiz;
    int lastSearch;

public:
    AVL()
    {
        this->raiz = NULL;
        this->lastSearch = 0;
    }
    void countSearh(int key, NodeAVL<T> *raiz)
    {
        this->lastSearch = 0;
        searh(key, raiz);
    }
    NodeAVL<T> *searh(int key, NodeAVL<T> *raiz)
    {
        this->lastSearch += 1;
        if (raiz == NULL)
        {
            return NULL;
        }
        else if (raiz->dato == key)
        {
            return raiz;
        }
        else if (raiz->dato < key)
        {
            return searh(key, raiz->derecho);
        }
        else if (raiz->dato > key)
        {
            return searh(key, raiz->izquierdo);
        }
    }
    int getFE(NodeAVL<T> *NodeAVL)
    {
        if (NodeAVL == NULL)
        {
            return -1;
        }
        else
        {
            return NodeAVL->fe;
        }
    }

    NodeAVL<T> *rotacionIzquierda(NodeAVL<T> *pNodeAVL)
    {
        NodeAVL<T> *aux = pNodeAVL->izquierdo;
        pNodeAVL->izquierdo = aux->derecho;

        aux->derecho = pNodeAVL;

        pNodeAVL->fe = max(this->getFE(pNodeAVL->izquierdo), this->getFE(pNodeAVL->derecho)) + 1;
        aux->fe = max(this->getFE(aux->izquierdo), this->getFE(aux->derecho)) + 1;

        return aux;
    }
    NodeAVL<T> *rotacionDerecha(NodeAVL<T> *pNodeAVL)
    {
        NodeAVL<T> *aux = pNodeAVL->derecho;
        pNodeAVL->derecho = aux->izquierdo;

        aux->izquierdo = pNodeAVL;

        pNodeAVL->fe = max(this->getFE(pNodeAVL->izquierdo), this->getFE(pNodeAVL->derecho)) + 1;
        aux->fe = max(this->getFE(aux->izquierdo), this->getFE(aux->derecho)) + 1;

        return aux;
    }
    NodeAVL<T> *rotacionDobleIzquierda(NodeAVL<T> *pNodeAVL)
    {
        NodeAVL<T> *aux;

        pNodeAVL->izquierdo = this->rotacionDerecha(pNodeAVL->izquierdo);
        aux = this->rotacionIzquierda(pNodeAVL);

        return aux;
    }
    NodeAVL<T> *rotacionDobleDerecha(NodeAVL<T> *pNodeAVL)
    {
        NodeAVL<T> *aux;

        pNodeAVL->derecho = this->rotacionIzquierda(pNodeAVL->derecho);
        aux = this->rotacionDerecha(pNodeAVL);

        return aux;
    }
    NodeAVL<T> *addNodeAVL(NodeAVL<T> *nuevo, NodeAVL<T> *subArbol)
    {
        NodeAVL<T> *nuevoPadre = subArbol;

        if (nuevo->dato < subArbol->dato)
        {
            if (subArbol->izquierdo == NULL)
            {
                subArbol->izquierdo = nuevo;
            }
            else
            {
                subArbol->izquierdo = this->addNodeAVL(nuevo, subArbol->izquierdo);

                int balance = this->getFE(subArbol->izquierdo) - this->getFE(subArbol->derecho);

                if (balance == 2)
                {
                    if (nuevo->dato < subArbol->izquierdo->dato)
                    {
                        nuevoPadre = this->rotacionIzquierda(subArbol);
                    }
                    else
                    {
                        nuevoPadre = this->rotacionDobleIzquierda(subArbol);
                    }
                }
            }
        }
        else if (nuevo->dato > subArbol->dato)
        {
            if (subArbol->derecho == NULL)
            {
                subArbol->derecho = nuevo;
            }
            else
            {
                subArbol->derecho = this->addNodeAVL(nuevo, subArbol->derecho);

                int balance = this->getFE(subArbol->derecho) - this->getFE(subArbol->izquierdo);

                if (balance == 2)
                {
                    if (nuevo->dato > subArbol->derecho->dato)
                    {
                        nuevoPadre = this->rotacionDerecha(subArbol);
                    }
                    else
                    {
                        nuevoPadre = this->rotacionDobleDerecha(subArbol);
                    }
                }
            }
        }
        // Actualizando factor de equilibrio
        if ((subArbol->izquierdo == NULL) && (subArbol->derecho != NULL))
        {
            subArbol->fe = subArbol->derecho->fe + 1;
        }
        else if ((subArbol->derecho == NULL) && (subArbol->izquierdo != NULL))
        {
            subArbol->fe = subArbol->izquierdo->fe + 1;
        }
        else
        {
            subArbol->fe = max(this->getFE(subArbol->izquierdo), this->getFE(subArbol->derecho)) + 1;
        }

        return nuevoPadre;
    }
    void add(int key, T* Pcontent)
    {
        NodeAVL<T> *nuevo = new NodeAVL<T>(key, Pcontent);

        if (this->raiz == NULL)
        {
            this->raiz = nuevo;
        }
        else
        {
            this->raiz = this->addNodeAVL(nuevo, raiz);
        }
    }

    NodeAVL<T> *getRaiz()
    {
        return this->raiz;
    }

    int getCount()
    {
        return this->lastSearch;
    }

    void inOrden(NodeAVL<T> *pNodeAVL)
    {
        if (pNodeAVL != NULL)
        {
            this->inOrden(pNodeAVL->izquierdo);
            cout << pNodeAVL->dato << ", ";
            this->inOrden(pNodeAVL->derecho);
        }
    }
};

#endif

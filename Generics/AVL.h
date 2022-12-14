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
    AVL() // The tree constructor
    {
        this->raiz = NULL;
        this->lastSearch = 0;
    }
    void countSearh(int key, NodeAVL<T> *raiz) // Searhes tree by potencial
    {
        this->lastSearch = 0;
        searh(key, raiz);
    }
    NodeAVL<T> *searh(int key, NodeAVL<T> *raiz) // Checks all nodes to kind the specific key
    {
        this->lastSearch += 1;
        if (raiz == NULL) // Position wasn't founded
        {
            return NULL;
        }
        else if (raiz->dato == key) // Psotion founded
        {
            return raiz;
        }
        else if (raiz->dato < key) // Uses recursion depending on the side of the tree changing the root
        {
            return searh(key, raiz->derecho);
        }
        else if (raiz->dato > key) // Uses recursion to look the key on the left side
        {
            return searh(key, raiz->izquierdo);
        }
    }

    int getFE(NodeAVL<T> *NodeAVL) // Checks the balance factor
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

    NodeAVL<T> *rotacionIzquierda(NodeAVL<T> *pNodeAVL) // Makes the specific rotation
    {
        NodeAVL<T> *aux = pNodeAVL->izquierdo; // Sets the left side on a temporal variable
        pNodeAVL->izquierdo = aux->derecho;    // The left side is replaces with the right side of aux. (aux was the original left side)

        aux->derecho = pNodeAVL; // The NULL node now is filled with the parameter node

        pNodeAVL->fe = max(this->getFE(pNodeAVL->izquierdo), this->getFE(pNodeAVL->derecho)) + 1; // Takes the grater value of balance factor and sets it on node AVL. It would be saving an integer. If the integer is negative means the left side is bigger
        aux->fe = max(this->getFE(aux->izquierdo), this->getFE(aux->derecho)) + 1;                // Takes the greater value of balace but from the aux vatiable
        return aux;
    }
    NodeAVL<T> *rotacionDerecha(NodeAVL<T> *pNodeAVL)
    {
        NodeAVL<T> *aux = pNodeAVL->derecho; // Sets the right side on a temporal variable
        pNodeAVL->derecho = aux->izquierdo;  // The right side is replaces with the left side of aux. (Aux was the original right side)

        aux->izquierdo = pNodeAVL; // The NULL node now is filled with the parameter node

        pNodeAVL->fe = max(this->getFE(pNodeAVL->izquierdo), this->getFE(pNodeAVL->derecho)) + 1; // Checks the balance looking for the bigger side. The result might be an integer positive or negative.
        aux->fe = max(this->getFE(aux->izquierdo), this->getFE(aux->derecho)) + 1;

        return aux;
    }
    NodeAVL<T> *rotacionDobleIzquierda(NodeAVL<T> *pNodeAVL) // Makes a left rigth rotation
    {
        NodeAVL<T> *aux;

        pNodeAVL->izquierdo = this->rotacionDerecha(pNodeAVL->izquierdo); // Makes a left rigth rotation
        aux = this->rotacionIzquierda(pNodeAVL);                          // With the result of the previos rotaiton makes another double left rotation

        return aux;
    }
    NodeAVL<T> *rotacionDobleDerecha(NodeAVL<T> *pNodeAVL) // Makes a double right rotation
    {
        NodeAVL<T> *aux;

        pNodeAVL->derecho = this->rotacionIzquierda(pNodeAVL->derecho); // Makes a right rotation
        aux = this->rotacionDerecha(pNodeAVL);                          // With the result of the previos rotaiton makes another double rigth rotation

        return aux;
    }
    NodeAVL<T> *addNodeAVL(NodeAVL<T> *nuevo, NodeAVL<T> *subArbol) // Adds the node on the tree
    {                                                               // The parameters are the new node and the previous root
        NodeAVL<T> *nuevoPadre = subArbol;

        if (nuevo->dato < subArbol->dato)
        {
            if (subArbol->izquierdo == NULL) // Validates if the data is smaller to locate it on the rigth position
            {
                subArbol->izquierdo = nuevo;
            }
            else
            {
                subArbol->izquierdo = this->addNodeAVL(nuevo, subArbol->izquierdo); // Adds the node on the new created side

                int balance = this->getFE(subArbol->izquierdo) - this->getFE(subArbol->derecho); // Checks the correct balance

                if (balance == 2)
                {
                    if (nuevo->dato < subArbol->izquierdo->dato)
                    {
                        nuevoPadre = this->rotacionIzquierda(subArbol); // If the balance is wrong makes a left turn
                    }
                    else
                    {
                        nuevoPadre = this->rotacionDobleIzquierda(subArbol); // If the balance is wrong makes a left turn
                    }
                }
            }
        }
        else if (nuevo->dato > subArbol->dato) // Validates if the data is bigger to locate it on the rigth position
        {
            if (subArbol->derecho == NULL)
            {
                subArbol->derecho = nuevo;
            }
            else // If the rigth node is different to NULL has to locate on a differnet place
            {
                subArbol->derecho = this->addNodeAVL(nuevo, subArbol->derecho); // Places the new node on the rigth

                int balance = this->getFE(subArbol->derecho) - this->getFE(subArbol->izquierdo); // Checkes the balance

                if (balance == 2) // Takes decition based on the tree balance
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
            // Saves the bigger balance factor
        }

        return nuevoPadre;
    }
    void add(int key, T *Pcontent) // Adds the data on the node, if there is no data simply add and saves the root
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

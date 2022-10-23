#include <iostream>

#ifndef NODEAVL

#define NODEAVL 1

using namespace std;

template <typename T>
class NodeAVL
{
public:
    int dato;
    T *content;
    int fe; // factor de equilibrio
    NodeAVL *izquierdo;
    NodeAVL *derecho;

    NodeAVL(int dato, T *content) // Node containing infomration about itself
    {
        this->content = content;
        this->dato = dato;
        this->fe = 0;
        this->izquierdo = NULL;
        this->derecho = NULL;
    }
};

#endif
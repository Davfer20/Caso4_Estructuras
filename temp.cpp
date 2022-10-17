#include <iostream>

using namespace std;

class Nodo {
    public:
        int     dato;
        int     fe;  // factor de equilibrio
        Nodo*   izquierdo;
        Nodo*   derecho;

        Nodo(int dato);
};

class AVL {
    private:
        Nodo* raiz;
    public:
        AVL();
        Nodo* buscar(int dato, Nodo* raiz);
        int   obtenerFE(Nodo* nodo);
        Nodo* rotacionIzquierda(Nodo* nodo);
        Nodo* rotacionDerecha(Nodo* nodo);
        Nodo* rotacionDobleIzquierda(Nodo* nodo);
        Nodo* rotacionDobleDerecha(Nodo* nodo);
        Nodo* insertarNodo(Nodo* nuevo, Nodo* subArbol);
        void  insertar(int dato);
        void  inOrden(Nodo* nodo);
        void  preOrden(Nodo* nodo);
        void  postOrden(Nodo* nodo);

        Nodo* obtenerRaiz();
};

Nodo::Nodo(int dato) {
    this->dato = dato;
    this->fe = 0;
    this->izquierdo = NULL;
    this->derecho = NULL;
}

AVL::AVL() {
    this->raiz = NULL;
}

Nodo* AVL::buscar(int dato, Nodo* raiz) {
    if (raiz == NULL) {
        return NULL;
    } else if (raiz->dato == dato) {
        return raiz;
    } else if (raiz->dato < dato) {
        return buscar(dato, raiz->derecho);
    } else if (raiz->dato > dato) {
        return buscar(dato, raiz->izquierdo);
    }
}

int AVL::obtenerFE(Nodo* nodo) {
    if (nodo == NULL) {
        return -1;
    } else {
        return nodo->fe;
    }
}

Nodo* AVL::rotacionIzquierda(Nodo* nodo) {
    Nodo* aux = nodo->izquierdo;
    nodo->izquierdo = aux->derecho;

    aux->derecho = nodo;

    nodo->fe = max(this->obtenerFE(nodo->izquierdo), this->obtenerFE(nodo->derecho)) + 1;
    aux->fe  = max(this->obtenerFE(aux->izquierdo), this->obtenerFE(aux->derecho)) + 1;

    return aux;
}

Nodo* AVL::rotacionDerecha(Nodo* nodo) {
    Nodo* aux = nodo->derecho;
    nodo->derecho = aux->izquierdo;

    aux->izquierdo = nodo;

    nodo->fe = max(this->obtenerFE(nodo->izquierdo), this->obtenerFE(nodo->derecho)) + 1;
    aux->fe  = max(this->obtenerFE(aux->izquierdo), this->obtenerFE(aux->derecho)) + 1;

    return aux;
}

Nodo* AVL::rotacionDobleIzquierda(Nodo* nodo) {
    Nodo* aux;

    nodo->izquierdo = this->rotacionDerecha(nodo->izquierdo);
    aux = this->rotacionIzquierda(nodo);

    return aux;
}

Nodo* AVL::rotacionDobleDerecha(Nodo* nodo) {
    Nodo* aux;

    nodo->derecho = this->rotacionIzquierda(nodo->derecho);
    aux = this->rotacionDerecha(nodo);

    return aux;
}

Nodo* AVL::insertarNodo(Nodo* nuevo, Nodo* subArbol) {
    Nodo* nuevoPadre = subArbol;

    if (nuevo->dato < subArbol->dato) {
        if (subArbol->izquierdo == NULL) {
            subArbol->izquierdo = nuevo;
        } else {
            subArbol->izquierdo = this->insertarNodo(nuevo, subArbol->izquierdo);

            int balance = this->obtenerFE(subArbol->izquierdo) - this->obtenerFE(subArbol->derecho);

            if (balance == 2) {
                if (nuevo->dato < subArbol->izquierdo->dato) {
                    nuevoPadre = this->rotacionIzquierda(subArbol);
                } else {
                    nuevoPadre = this->rotacionDobleIzquierda(subArbol);
                }
            }

        }
    } else if (nuevo->dato > subArbol->dato) {
        if (subArbol->derecho == NULL) {
            subArbol->derecho = nuevo;
        } else {
            subArbol->derecho = this->insertarNodo(nuevo, subArbol->derecho);

            int balance = this->obtenerFE(subArbol->derecho) - this->obtenerFE(subArbol->izquierdo);

            if (balance == 2) {
                if (nuevo->dato > subArbol->derecho->dato) {
                    nuevoPadre = this->rotacionDerecha(subArbol);
                } else {
                    nuevoPadre = this->rotacionDobleDerecha(subArbol);
                }
            }
        }
    } else {
        cout << "Nodo duplicado!" << endl;
    }

    // Actualizando factor de equilibrio
    if ((subArbol->izquierdo == NULL) && (subArbol->derecho != NULL)) {
        subArbol->fe = subArbol->derecho->fe + 1;
    } else if ((subArbol->derecho == NULL) && (subArbol->izquierdo != NULL)) {
        subArbol->fe = subArbol->izquierdo->fe + 1;
    } else {
        subArbol->fe = max(this->obtenerFE(subArbol->izquierdo), this->obtenerFE(subArbol->derecho)) + 1;
    }

    return nuevoPadre;
}

void AVL::insertar(int dato) {
    Nodo* nuevo = new Nodo(dato);

    if (this->raiz == NULL) {
        this->raiz = nuevo;
    } else {
        this->raiz = this->insertarNodo(nuevo, raiz);
    }
}

void AVL::inOrden(Nodo* nodo) {
    if (nodo != NULL) {
        this->inOrden(nodo->izquierdo);
        cout << nodo->dato << ", ";
        this->inOrden(nodo->derecho);
    }
}

void AVL::preOrden(Nodo* nodo) {
    if (nodo != NULL) {
        cout << nodo->dato << ", ";
        this->preOrden(nodo->izquierdo);
        this->preOrden(nodo->derecho);
    }
}

void AVL::postOrden(Nodo* nodo) {
    if (nodo != NULL) {
        this->postOrden(nodo->izquierdo);
        this->postOrden(nodo->derecho);
        cout << nodo->dato << ", ";
    }
}

Nodo* AVL::obtenerRaiz() {
    return this->raiz;
}

int main () {

    cout << "Arbol AVL" << endl;

    AVL* arbol = new AVL();

    arbol->insertar(10);
    arbol->insertar(5);
    arbol->insertar(13);
    arbol->insertar(1);
    arbol->insertar(6);
    arbol->insertar(17);
    arbol->insertar(16);

    arbol->postOrden(arbol->obtenerRaiz());

    return 0;
}
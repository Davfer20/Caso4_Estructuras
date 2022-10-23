#include "Sala.h"
#include "..\Generics\List.h"
#include "..\Global\Constants.h"

#ifndef MINA

#define MINA 1

class Mina
{
private:
    int salasT;        // Cantidad de Salas por crear
    List<Sala> *Salas; // Lista con todas las Salas de la mina (En orden de creacion)
    // vector<Sala*> Salas;
    Sala *SalaP; // Sala Principal/Raiz

public:
    // Contructor de Mina con Sala Principal
    Mina()
    {
        this->Salas = new List<Sala>();
        Sala *Sprincipal = new Sala();
        this->SalaP = Sprincipal;
        // Salas.push_back(SalaP);
        this->Salas->add(SalaP);
        this->salasT = 16;
        this->salasT -= 1;
    }

    // Funcion que crea las adyacencias de la Sala Principal
    void addToSalap()
    {
        srand(time(0));
        int rCant = rand() % 3 + 2;
        int rDire;
        vector<int> Avail;

        while (rCant != 0)
        {
            Avail = SalaP->available(); // Puertas disponibles
            int max = Avail.size();
            rDire = rand();
            rDire %= max;
            rDire = Avail[rDire]; // Se toma el index y se crea un nodo
            Sala *nuevaSala = new Sala(SalaP, rDire, randomTunel());
            // Salas.push_back(nuevaSala);
            Salas->add(nuevaSala);
            --rCant;
            this->salasT -= 1;
        }
    }

    // !Validar uso
    int getsalasT()
    {
        return salasT;
    }

    List<Sala> *getSalasList()
    {
        return this->Salas;
    }

    // Retorna un numero random de Adyacencias, sin superar al limite
    int randomPuertas()
    {
        int rDire;
        if (salasT >= 3)
        {
            rDire = rand();
            rDire %= 2;
            rDire += 1;
        }
        else
        {
            rDire = salasT;
        }
        this->salasT -= rDire;
        return rDire;
    }

    // Retorna si asignar un tunel
    bool randomTunel()
    {
        bool resul;
        resul = rand() % 3;
        return !resul;
    }

    // Funcion que genera el sistema de Salas hasta agotar las puertas
    void addSalasTotal()
    {
        int count = 1;

        while (salasT != 0) // Seria bueno hacer en la lista un getlast
        {
            if (!Salas->find(count)->getDone())
            {
                int rDire;
                int cDoors;
                vector<int> Avail; // No se si estos valores pueden ir aca
                // Sala* SalaActual = Salas[count];
                Sala *SalaActual = Salas->find(count);
                // *Salas->find(count) = *SalaActual;   // No se si esto esta correcto

                cDoors = randomPuertas(); // Puertas a crear con habitaciones totales

                while (cDoors != 0)
                {
                    Avail = SalaActual->available(); // Puertas disponibles
                    int max = Avail.size();

                    rDire = rand();
                    rDire %= max;

                    rDire = Avail[rDire]; // Se toma el index y se crea un nodo

                    Sala *nuevaSala = new Sala(SalaActual, rDire, randomTunel());
                    // Salas.push_back(nuevaSala);
                    Salas->add(nuevaSala);
                    --cDoors;
                }
                SalaActual->setDone();
                ++count;
            }
        }
    }
};

#endif
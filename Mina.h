#include "Sala.h"
#include "List.h"
#include <vector>

class Mina
{
private:
    int salasT = 20;
    List<Sala> *Salas;
    Sala *SalaP;
    Sala *SalaActual;

public:
    Mina()
    {
        Sala *Sprincipal = new Sala();
        this->SalaP = Sprincipal;
    }

    void addToSalap()
    {
        srand(time(0));
        int rCant = rand() % 3 + 2;
        int rDire;
        vector<int> Avail;

        while (rCant != 0)
        {
            Avail = SalaP->available();
            int max = Avail.size(); // 0 SUR, 1 NORTE, 2 ESTE, 3 OESTE
            rDire = rand();
            rDire %= max;
            rDire = Avail[rDire];
            Sala *nuevaSala = new Sala(SalaP, rDire);
            Salas->add(nuevaSala);
            --rCant;
        }
    }

    int getsalasT()
    {
        return salasT;
    }

    int randomPuertas()
    {
        int rDire;
        if (salasT >= 3)
        {
            rDire = rand();
            rDire %= 3;
        }
        else
        {
            rDire = rand();
            rDire %= salasT;
        }
        this->salasT = salasT - rDire;
        return rDire;
    }
    void addSalasTotal()
    {
        while (salasT != 0) // Seria bueno hacer en la lista un get last
        {
            for (int i = 0; i < Salas->getSize(); i++)
            {
                if (Salas->find(i)->getDone() == false)
                {
                    int rDire;
                    int cDoors;
                    vector<int> Avail; // No se si estos valores pueden ir aca

                    *Salas->find(i) = *SalaActual;   // No se si esto esta correcto
                    Avail = SalaActual->available(); // Se guarda cantidad disponible
                    int max = Avail.size();          // Maximo disponible
                    cDoors = randomPuertas();        // Puertas a crear con habitaciones totales

                    while (cDoors = !0) // Creo que no valida si es 0
                    {
                        rDire = rand();
                        rDire %= max;
                        rDire = Avail[rDire]; // Se toma el index y se crea un nodo
                        Sala *nuevaSala = new Sala(SalaActual, rDire);
                        Salas->add(nuevaSala);
                        --cDoors;
                    }
                    SalaActual->setDone();
                }
            }
        }
    }
};

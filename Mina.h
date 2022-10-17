#include "Sala.h"
#include "List.h"
#include "Constants.h"

#ifndef MINA

#define MINA 1

class Mina
{
private:
    int salasT;
    List<Sala>* Salas;
    //vector<Sala*> Salas;
    Sala *SalaP;

public:
    Mina()
    {   
        this->Salas = new List<Sala>();
        Sala *Sprincipal = new Sala();
        this->SalaP = Sprincipal;
        //Salas.push_back(SalaP);
        this->Salas->add(SalaP);
        this->salasT = 16;
        this->salasT -= 1;
    }

    void addToSalap()
    {
        srand(time(0));
        int rCant = rand() % 3 + 2;
        int rDire;
        vector<int> Avail;

        while (rCant != 0)
        {
            Avail = SalaP->available();    // Puertas disponibles
            int max = Avail.size(); 
            rDire = rand();
            rDire %= max;
            rDire = Avail[rDire]; // Se toma el index y se crea un nodo
            Sala *nuevaSala = new Sala(SalaP, rDire, randomTunel());
            //Salas.push_back(nuevaSala);
            Salas->add(nuevaSala);
            --rCant;
            this->salasT -= 1;
        }
    }

    int getsalasT()
    {
        return salasT;
    }

    List<Sala>* getSalasList()
    {
        return this->Salas;
    }

    int randomPuertas()
    {
        int rDire;
        if (salasT >= 3) {
            rDire = rand();
            rDire %= 2;
            rDire += 1;
        } else {
            rDire = salasT;
        }
        this->salasT -= rDire;
        return rDire;
    }

    bool randomTunel()
    {
        bool resul;
        resul = rand() % 3;
        return !resul;
    }

    void addSalasTotal()
    {
        int count = 1;

        while (salasT != 0) // Seria bueno hacer en la lista un get last
        {
            if (!Salas->find(count)->getDone())
            {
                int rDire;
                int cDoors;
                vector<int> Avail; // No se si estos valores pueden ir aca
                //Sala* SalaActual = Salas[count];
                Sala* SalaActual = Salas->find(count);
                // *Salas->find(count) = *SalaActual;   // No se si esto esta correcto

                cDoors = randomPuertas();        // Puertas a crear con habitaciones totales

                while (cDoors != 0) // Creo que no valida si es 0
                {   
                    Avail = SalaActual->available();    // Puertas disponibles
                    int max = Avail.size();  

                    rDire = rand();
                    rDire %= max;

                    rDire = Avail[rDire]; // Se toma el index y se crea un nodo

                    Sala *nuevaSala = new Sala(SalaActual, rDire, randomTunel());
                    //Salas.push_back(nuevaSala);
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
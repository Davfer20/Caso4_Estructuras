#include "Sala.h"
#include "List.h"
#include <vector>

class Mina
{
    private:
        List<Sala>* Salas;
        Sala* SalaP; 
    public:
        Mina() {
            Sala* Sprincipal = new Sala();
            this->SalaP = Sprincipal;
        }

        void addToSalap () {
            srand(time(0));
            int rCant = rand() % 3 + 2; 
            int rDire;
            vector<int> Avail;

            while (rCant != 0) {
                Avail = SalaP->available();
                int max = Avail.size();                            // 0 SUR, 1 NORTE, 2 ESTE, 3 OESTE
                rDire = rand();
                rDire %= max;
                rDire = Avail[rDire];
                Sala* nuevaSala = new Sala(SalaP, rDire);
                --rCant;      
            }
            
        }
};



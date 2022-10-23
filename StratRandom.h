#include "IStrat.h"

class StratRandom : public IStrat
{
private:
public:
    StratRandom()
    {
    }
    int chooseSala(vector<int> AvailPaths)
    {
        int rDire;
        int max = AvailPaths.size();
        rDire = rand();
        rDire %= max;              // Hace random del tamaño para escojer
        rDire = AvailPaths[rDire]; // Se guarda el valor en rDire
        return rDire;
    }

    bool enterTunel()
    {
        int rDire;
        return rDire = (rand() % 2); // Devuelve bool con 50% de probabilidad
    }
    bool mineOrgGodeep(int pDeep)
    {
        int rDire;
        return rDire = (rand() % 2);
    }
    bool choosePath(int Opcion) // 1 only right, 2 left & 3 both
    {
        if (Opcion == 3)
        {
            int rDire;
            Opcion = ((rand() % 2) + 1);
        }

        return Opcion;
    }
    string getName()
    {
        return "Random Stategy";
    }
};

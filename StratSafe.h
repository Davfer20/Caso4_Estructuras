#include "IStrat.h"

class StratSafe : public IStrat
{
private:
    /* Atributos */
public:
    StratSafe()
    {
    }
    int chooseSala(vector<int> AvailPaths)
    {
        // int rDire;
        // int max = AvailPaths.size();
        // rDire = rand();
        // rDire %= max;              // Hace random del tamaño para escojer
        // rDire = AvailPaths[rDire]; // Se puede hacer igual que random sino solo toma el valor 0
        // return rDire;
        return AvailPaths[0];
    }
    bool enterTunel()
    {
        return true;
    }
    bool mineOrgGodeep(int pDeep)
    {
        return true;
    }
    bool choosePath(int Opcion)
    {
        if (Opcion == 3)
        {
            int rDire;
            Opcion = ((rand() % 2) + 1); // Same as random becuase doesnt matter
        }
        return Opcion;
    }

    string getName()
    {
        return "Safe Stategy";
    }
};
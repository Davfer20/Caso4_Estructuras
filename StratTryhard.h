#include "IStrat.h"

class StratTryhard : public IStrat
{
private:
    /* Atributos */
public:
    StratTryhard()
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
        return true;
    }
    bool mineOrgGodeep(int pDeep)
    {
        bool option = false;
        Singleton *var = var->getInstance();
        int pTime = var->getTimer();

        if (pTime < 20)
        {
            option = true;
        }

        if (pDeep > 450)
        {
            option = true;
        }
        return option;
    }
    bool choosePath(int Opcion)
    {
        {
        if (Opcion == 3)
        {
            Opcion = 1;
        }

        return Opcion;
    }
    }

    string getName()
    {
        return "Tryhard strategy";
    }
};
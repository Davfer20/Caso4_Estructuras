#include "IStrat.h"

#ifndef STRATS

#define STRATS 1

class StratSafe : public IStrat
{
public:
    StratSafe()
    {
    }
    int chooseSala(vector<int> AvailPaths)
    {
        int rDire;
        int max = AvailPaths.size();
        rDire = rand();
        rDire %= max; // Hace random del tamaño para escojer
        rDire = AvailPaths[rDire];
        return rDire;
    }
    bool enterTunel(NodeAVL<Chamber> *chamberNode)
    {

        if (chamberNode->derecho != NULL)
        {
            if (chamberNode->derecho->content->ifValid())
            {
                return true;
            }
        }
        if (chamberNode->izquierdo != NULL)
        {
            if (chamberNode->izquierdo->content->ifValid())
            {
                return true;
            }
        }
        return false;
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
            Opcion = rand() % 2 + 1; // Same as random becuase doesnt matter
        }
        return Opcion - 1;
    }

    string getName()
    {
        return "Safe Stategy";
    }
};

#endif
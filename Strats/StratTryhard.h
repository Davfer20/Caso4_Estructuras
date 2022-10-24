#include "IStrat.h"

#ifndef STRATT

#define STRATT 1

class StratTryhard : public IStrat
{
public:
    StratTryhard()
    {
    }
    int chooseSala(vector<int> AvailPaths)
    {
        int rDire;
        int max = AvailPaths.size();
        rDire = rand();
        rDire %= max;
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
        bool option = false;
        Singleton *var = var->getInstance();
        int pTime = var->getTimer();

        if (pTime < 10 || pDeep > 3)
        {
            option = true;
        }
        return option;
    }
    bool choosePath(int Opcion)
    {
        if (Opcion == 3)
        {
            Opcion = 1;
        }
        return Opcion - 1;
    }

    string getName()
    {
        return "Tryhard strategy";
    }
};

#endif
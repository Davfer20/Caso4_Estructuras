#include "Mina.h"
#include "Sala.h"
#include "..\Miners\IMiner.h"
#include "..\Miners\Carrier.h"
#include "..\Miners\Explorer.h"
#include "..\Miners\Driller.h"
#include "..\Strats\IStrat.h"
#include "..\Strats\StratRandom.h"
#include "..\Strats\StratSafe.h"
#include "..\Strats\StratTryhard.h"
#include "..\Global\Singleton.h"
#include <thread>

using namespace std;

struct timespec sec = {1, 0}; // Pausa de un segundo

int main()
{
    Singleton *var = var->getInstance();
    Mina *mina = new Mina();
    mina->addToSalap();
    mina->addSalasTotal();
    
    int anwser;
    cout << "Turno del Player1" << endl;

    vector<IMiner *> mineros1;
    int cant = 1;
    while (cant !=4)
    {
        IMiner *minero1;
        while (true)
        {
            int type = 0;
            cout << endl
                 << endl
                 << endl
                 << "1. Explorador" << endl
                 << "2. Topo" << endl
                 << "3. Carguero" << endl
                 << "Seleccione al Minero " << cant << endl;
            cin >> anwser;
            switch (anwser)
            {
            case 1:
                minero1 = new Explorer(mina);
                break;
            case 2:
                minero1 = new Driller(mina);
                break;
            case 3:
                minero1 = new Carrier(mina);
                break;
            default:
                ++type;
                break;
            }
            if (!type)
            {
                break;
            }
            cout << "ERROR: Numero erroneo, presione <Enter> para volverlo a intentar" << endl;
            cin >> anwser;
        }

        IStrat *strat1;
        while (true)
        {
            int strat = 0;
            cout << endl
                 << endl
                 << endl
                 << "1. Tryhard" << endl
                 << "2. A la segura" << endl
                 << "3. Al azar" << endl
                 << "Seleccione la estrategia del Minero " << cant << endl;
            cin >> anwser;
            switch (anwser)
            {
            case 1:
                strat1 = new StratTryhard();
                break;
            case 2:
                strat1 = new StratSafe();
                break;
            case 3:
                strat1 = new StratRandom();
                break;
            default:
                ++strat;
                break;
            }
            if (!strat)
            {
                break;
            }
            cout << "ERROR: Numero erroneo, presione <Enter> para volverlo a intentar" << endl;
            cin >> anwser;
        }
        minero1->setStrat(strat1);
        mineros1.push_back(minero1);
        ++cant;
    }

    int count = 90;
    int puntaje1;
    while (count >= 0)
    {
        srand(time(0));
        cout << "Tiempo restante: " << count << endl;
        puntaje1 = var->getLoad();
        cout << "Material recogido: " << puntaje1 << endl;
        for (int i = 0; i < mineros1.size(); i++)
        {
            IMiner *Nminer = mineros1[i];

            Nminer->getState();
            switch (Nminer->getState())
            {
            case 0:
                Nminer->exploring();
                break;
            case 1:
                Nminer->mining();
                break;
            case 2:
                Nminer->unloading();
                break;
            default:
                Nminer->death();
                break;
            }

            cout << "═══════════════════════╣ Player 1 ╠════════════════════════" << endl
                 << "Minero " << i + 1 << ": " << Nminer->getMname()
                 << "           "
                 << "Inventario: " << Nminer->getInventory() << "/" << Nminer->getCap() << endl
                 << "Estrategia: " << Nminer->getStrat() << endl
                 << "Estado: " << Nminer->getAction() << endl
                 << "Material en la recamara: " << Nminer->getMrlCurrentChamb() << endl;
        }
        // CLS Casero
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
        count -= 1;
        var->setTimer(count);
        pthread_delay_np(&sec);
    }

    Mina *mina2 = new Mina();
    mina2->addToSalap();
    mina2->addSalasTotal();

    cout << "Se ha acabado el tiempo..." << endl;
    //////////////
    // Player 2 //
    //////////////
    cout << "Turno del Player2" << endl;

    var->resetSingle();

    vector<IMiner *> mineros2;
    cant = 1;
    while (cant !=4)

    {
        IMiner *minero2;
        while (true)
        {
            int type = 0;
            cout << endl
                 << endl
                 << endl
                 << "1. Explorador" << endl
                 << "2. Topo" << endl
                 << "3. Carguero" << endl
                 << "Seleccione al Minero " << cant << endl;
            cin >> anwser;
            switch (anwser)
            {
            case 1:
                minero2 = new Explorer(mina2);
                break;
            case 2:
                minero2 = new Driller(mina2);
                break;
            case 3:
                minero2 = new Carrier(mina2);
                break;
            default:
                ++type;
                break;
            }
            if (!type)
            {
                break;
            }
            cout << "ERROR: Numero erroneo, presione <Enter> para volverlo a intentar" << endl;
            cin >> anwser;
        }

        IStrat *strat2;
        while (true)
        {
            int strat = 0;
            cout << endl
                 << endl
                 << endl
                 << "1. Tryhard" << endl
                 << "2. A la segura" << endl
                 << "3. Al azar" << endl
                 << "Seleccione la estrategia del Minero " << cant << endl;
            cin >> anwser;
            switch (anwser)
            {
            case 1:
                strat2 = new StratTryhard();
                break;
            case 2:
                strat2 = new StratSafe();
                break;
            case 3:
                strat2 = new StratRandom();
                break;
            default:
                ++strat;
                break;
            }
            if (!strat)
            {
                break;
            }
            cout << "ERROR: Numero erroneo, presione <Enter> para volverlo a intentar" << endl;
            cin >> anwser;
        }
        minero2->setStrat(strat2);
        mineros2.push_back(minero2);
        ++cant;
    }


    count = 90;
    int puntaje2;
    while (count >= 0)
    {
        srand(time(0));
        cout << "Tiempo restante: " << count << endl;
        puntaje2 = var->getLoad();
        cout << "Material recogido: " << puntaje2 << endl;
        for (int i = 0; i < mineros2.size(); i++)
        {
            IMiner *Nminer = mineros2[i];

            Nminer->getState();
            switch (Nminer->getState())
            {
            case 0:
                Nminer->exploring();
                break;
            case 1:
                Nminer->mining();
                break;
            case 2:
                Nminer->unloading();
                break;
            default:
                Nminer->death();
                break;
            }

            cout << "═══════════════════════╣ Player 2 ╠════════════════════════" << endl
                 << "Minero " << i + 1 << ": " << Nminer->getMname()
                 << "           "
                 << "Inventario: " << Nminer->getInventory() << "/" << Nminer->getCap() << endl
                 << "Estrategia: " << Nminer->getStrat() << endl
                 << "Estado: " << Nminer->getAction() << endl
                 << "Material en la recamara: " << Nminer->getMrlCurrentChamb() << endl;
        }
        // CLS Casero
        cout << endl
             << endl
             << endl
             << endl
             << endl;
        count -= 1;
        var->setTimer(count);
        pthread_delay_np(&sec);
    }

    string resul = puntaje1 > puntaje2 ? "Ha ganado el player 1" : "Ha ganado el player 2";

    cout << "Se ha acabado el tiempo..." << endl;

    cout << "Procesando resultados..." << endl;

    pthread_delay_np(&sec);

    cout << resul << "!!!  " << puntaje1 << " - " << puntaje2 <<endl;
    
    // Queda pendiente
    // Constants

    return 0;
}
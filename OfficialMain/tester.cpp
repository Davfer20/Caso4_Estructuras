#include "Mina.h"
#include "Sala.h"
#include "Miner.h"
#include "..\Global\Singleton.h"
#include <thread>

using namespace std;

struct timespec sec = {1, 0}; // Pausa de un segundo

int main()
{
    Singleton *var = var->getInstance();
    Mina *mina1 = new Mina();
    mina1->addToSalap();
    mina1->addSalasTotal();
    
    int anwser;
    cout << "Presiones <Enter> para comenzar Player1" << endl;
    cin >> anwser;
    
    cout << "Seleccione al primer Minero" << endl;



    Miner *minero1 = new Miner(0, 0, mina1);
    Miner *minero2 = new Miner(0, 0, mina1);
    Miner *minero3 = new Miner(0, 0, mina1);

    vector<Miner *> mineros;
    mineros.push_back(minero1);
    mineros.push_back(minero2);
    mineros.push_back(minero3);

    int count = 0;
    int puntaje;
    while (count <= 90)
    {
        srand(time(0));
        cout << "Tiempo restante: " << 90 - count << endl;
        puntaje = var->getLoad();
        cout << "Material recogido: " << puntaje << endl;
        for (int i = 0; i < mineros.size(); i++)
        {
            Miner *Nminer = mineros[i];

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

            cout << "===========================================" << endl;
            cout << "Minero " << i + 1 << ": " << Nminer->getMname();
            cout << "           ";
            cout << "Inventario: " << Nminer->getInventory() << "/" << Nminer->getCap() << endl;
            cout << "Estado: " << Nminer->getAction() << endl;
            cout << "Material en la recamara: " << Nminer->getMrlCurrentChamb() << endl;
        }
        cout << endl
             << endl
             << endl
             << endl
             << endl
             << endl;
        count += 1;
        var->setTimer(count);
        pthread_delay_np(&sec);
    }

    cout << "Puntaje Obtenido: " << puntaje << "!!!" << endl;

    // Queda pendiente
    // Herencia en los mineros, y con esto los strats [Planeamiento en miro]
    // Sistema de eleccion de personajes y juego por turnos [Cambios pequeños en el main]

    return 0;
}
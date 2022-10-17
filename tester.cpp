#include "Mina.h"
#include "Sala.h"
#include "Miner.h"
#include <thread>

using namespace std;

struct timespec sec2 = {1, 0}; // Pausa de un segundo

int main()
{

    Mina *mina1 = new Mina();
    mina1->addToSalap();
    mina1->addSalasTotal();
    Miner *minero1 = new Miner(0, 0, mina1);
    Miner *minero2 = new Miner(1, 0, mina1);
    Miner *minero3 = new Miner(2, 0, mina1);

    thread t1(&Miner::mining, minero1);
    t1.detach();
    thread t2(&Miner::mining, minero2);
    t2.detach();
    thread t3(&Miner::mining, minero3);
    t3.detach();

    int count = 0;
    while (count < 90)
    {
        count += 1;
        pthread_delay_np(&sec1);
    }
    

    /*
    int totalDis = 0;
    Chamber* chamber1 = new Chamber(0);
    totalDis = chamber1->getTotDis();

    Chamber *chamber2 = new Chamber(totalDis);
    totalDis = chamber2->getTotDis();

    Chamber *chamber3 = new Chamber(totalDis);
    totalDis = chamber3->getTotDis();

    Chamber *chamber4 = new Chamber(totalDis);
    totalDis = chamber4->getTotDis();

    Chamber *chamber5 = new Chamber(totalDis);
    totalDis = chamber5->getTotDis();

    Chamber *chamber6 = new Chamber(totalDis);
    totalDis = chamber6->getTotDis();

    Tunel* tunel = new Tunel();
    tunel->add(chamber1);
    tunel->add(chamber2);
    tunel->add(chamber3);
    tunel->add(chamber4);
    tunel->add(chamber5);
    tunel->add(chamber6);

    tunel->postOrden(tunel->getRaiz());
    */
    return 0;
}
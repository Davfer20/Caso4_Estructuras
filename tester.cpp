#include "Mina.h"
#include "Sala.h"
#include "Miner.h"
#include <thread>

using namespace std;



int main()
{
    
    Mina *mina1 = new Mina();
    mina1->addToSalap();
    mina1->addSalasTotal();
    Miner* minero1 = new Miner(0, 0, mina1);
    minero1->start();
    Miner* minero2 = new Miner(1, 0, mina1);
    minero2->start();


    return 0;
}
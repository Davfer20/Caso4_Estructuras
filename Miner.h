#include "Sala.h"
#include "Mina.h"
#include "List.h"
#include <string.h>
#include <thread>
#include <iostream>

#ifndef MINER

#define MINER 1

using namespace std; 

struct timespec sec1 = {0, 100}; // Pausa de un segundo 

class Miner
{
    private:
        Sala* currentSala;
        vector<int> disPaths;
        string action;
        string Mname;
        Mina* currentMina;
        int Mtype; // 0 - Explorer, 1 - Carrier, 2 - Driller
        int Mstrat;
        int inventory;
        int cap;
        int speed;
        int lastDir;


    public:
        Miner(int PmType, int PmStrat, Mina* Pmina) { 
            this->currentMina = Pmina;
            this->currentSala = Pmina->getSalasList()->find(0);

            this->Mstrat = PmStrat;
            switch (PmType)
            {
            case 0:
                this->Mtype = 0;
                this->Mname = "Explorer";
                this->speed = 20;
                this->cap = 8;
                break;
            case 1:
                this->Mtype = 1;
                this->Mname = "Carrier";
                this->speed = 10;
                this->cap = 40;
                break;
            
            default:
                this->Mtype = 2;
                this->Mname = "Driller";
                this->speed = 7;
                this->cap = 15;
                break;
            }
        }
        string getMname() {
            return this->Mname;
        }

        void mining() {
            while (true) {
                pthread_delay_np(&sec1);
                cout << "El " << this->getMname() << " está en la sala " << currentSala->getID() << endl;
                if (currentSala->getIfTunel() && !(rand() % 3))
                {
                    break;   
                }
                
                disPaths = currentSala->availablePaths();
                int rDire;
                int max = disPaths.size();  
                rDire = rand();
                rDire %= max;  
                rDire = disPaths[rDire];
                this->currentSala = currentSala->getSalaDir(rDire);
            }
            cout << "El " << this->getMname() << " entró al tunel de la sala " << currentSala->getID() << endl; 
        }
 Miner* minero1 = new Miner(0, 0, mina1);
    minero1->start();
        void start () {
            mining();
        }
};

#endif

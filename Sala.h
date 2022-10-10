#include "Tunel.h"
#include "List.h"
#include <iostream>


#ifndef SALA 

#define SALA 1

using namespace std;

class Sala {
    private:
        bool ifTunel;
        Tunel *tunel;
        Sala *south;
        Sala *north;
        Sala *west;
        Sala *east;

    public:
        Sala() {
            this->south = this->north = this->east = this->west = NULL;
        }

        Sala(Sala* adya, int dire) {
            Sala();
            switch (dire)
            {
            case 0:
                this->south = adya;
                adya->setNorth(this);
                break;

            case 1:
                this->north = adya;
                adya->setSouth(this);
                break;

            case 2:
                this->east = adya;
                adya->setWest(this);
                break;

            default:
                this->west = adya;
                adya->setEast(this);
                break;
            }
            this->ifTunel = false;
        }


        Sala(Sala* adya, int dire, Tunel* ptunel) {
            Sala(adya, dire);
            this->ifTunel = true;
            this->tunel = ptunel;

        }

        void setSouth (Sala* pSala) {
            this->south = pSala;
        }

        void setNorth (Sala* pSala) {
            this->north = pSala;
        }

        void setEast (Sala* pSala) {
            this->east = pSala;
        }

        void setWest (Sala* pSala) {
            this->west = pSala;
        }

        List<int> available () {
            List<int>* availablesN = new List<int>();

            if (south) {
                availablesN->add(0)
            }
            if (north) {
                availablesN->add(1)
            }
            if (east) {
                availablesN->add(2)
            }
            if (west) {
                availablesN->add(3)
            }
            return availablesN
        }



};

#endif
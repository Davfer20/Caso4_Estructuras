#include "Tunel.h"
#include "List.h"
#include <iostream>
#include <vector>


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
            this->ifTunel = false;
            this->south = this->north = this->east = this->west = NULL;
        }

        Sala(Sala* adya, int dire) {
            Sala();
            switch (dire)
            {
            case 1:
                this->south = adya;
                adya->setNorth(this);
                break;

            case 0:
                this->north = adya;
                adya->setSouth(this);
                break;

            case 3:
                this->east = adya;
                adya->setWest(this);
                break;

            default:
                this->west = adya;
                adya->setEast(this);
                break;
            }
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

        vector<int> available () {                           // [1,0,1,0]
            vector<int> availablesN;

            if (south == NULL) {
                availablesN.push_back(0);
            } 
            if (north == NULL) {
                availablesN.push_back(1);
            } 
            if (east == NULL) {
                availablesN.push_back(2);
            } 
            if (west == NULL) {
                availablesN.push_back(3);
            } 
            return availablesN;
        }



};

#endif
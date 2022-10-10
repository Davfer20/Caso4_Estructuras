#include <Tunel.h>

#ifndef SALA 

#define SALA 1

using namespace std;

#define south 0
#define north 1
#define east 2
#define west 3

template <class T>
class Sala {
    private:
        bool ifTunel;
        Tunel *tunel;
        Sala *south;
        Sala *north;
        Sala *west;
        Sala *east;

  
    
    public:
        Sala(Sala* adya, int dire) {
            this->south = this->north = this->east = this->west = NULL;

            switch (dire)
            {
            case 0:
                this->south = adya;
                break;

            case 1:
                this->north = adya;
                break;

            case 2:
                this->east = adya;
                break: 

            default:
                this->west = adya;
                break;
            }
            this->ifTunel = false;
        }


        Sala(Sala* adya, int dire, Tunel* ptunel) {
            Sala(adya, dire);
            this->ifTunel = true;
            this->tunel = ptunel;

        }


};

#endif
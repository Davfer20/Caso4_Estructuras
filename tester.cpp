#include "Tunel.h"
#include "Sala.h"

using namespace std;

int main()
{
    
    Sala* sala1 = new Sala();

    Sala* sala2 = new Sala(sala1, 3);


    return 0;
}

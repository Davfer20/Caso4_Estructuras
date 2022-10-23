#include <vector>
#include <string>

using namespace std;

class IStrat
{
protected:
public:
    virtual int chooseSala(vector<int> AvailPaths) = 0; // Retorna el numero de la direccion
    virtual bool enterTunel() = 0;                      // True = yes, False = no
    virtual bool mineOrgGodeep(int pDeep) = 0;          // True = Mine, False = Go Deep
    virtual bool choosePath(int Opcion) = 0;            // True = Left, False = Right
    virtual string getName() = 0;
};
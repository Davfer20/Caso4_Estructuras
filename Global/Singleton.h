#include <iostream>

#ifndef SINGLE

#define SINGLE 1

using namespace std;

// Patron Singleton empleado para variables globales
class Singleton
{
   static Singleton *instance;
   int salaID;
   int load;
   int timer;

   // Private constructor so that no objects can be created.
   Singleton()
   {
      salaID = 1; // Contador de ID de las salas
      load = 0;   // Contador del mineral recogido
      timer = 0;  // Temporizador de la partida
   }

public:
   static Singleton *getInstance()
   {
      if (!instance)
         instance = new Singleton;
      return instance;
   }

   // Retorna el ID actual
   int getData()
   {
      return this->salaID;
   }
   // Incrementa el ID
   void IncData()
   {
      this->salaID += 1;
   }

   void addLoad(int pload)
   {
      this->load += pload;
   }

   int getLoad()
   {
      return this->load;
   }

   int getTimer()
   {
      return this->timer;
   }

   void setTimer(int ptimer)
   {
      this->timer = ptimer;
   }

   void resetSingle() {
      this->timer = 0;
      this->salaID = 1;
      this->load = 0;
   }
};

#endif
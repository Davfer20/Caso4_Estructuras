#include <iostream>

#ifndef SINGLE

#define SINGLE 1

using namespace std;

class Singleton {
   static Singleton *instance;
   int salaID;
 
   // Private constructor so that no objects can be created.
   Singleton() {
      salaID = 1;
   }

   public:
   static Singleton *getInstance() {
      if (!instance)
      instance = new Singleton;
      return instance;
   }

   int getData() {
      return this->salaID;
   }

   void IncData() {
      this->salaID += 1;
   }
};

#endif
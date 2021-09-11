#pragma once
#include "CommonModule.h"
#include <vector>
#include "Spectacle.h"

class Database {

public:

   std::vector<Spectacle*> spectacle;
   void init()
   {
      spectacle.push_back(new Spectacle("Zemsta", "2021-10-19", 20));
      spectacle.push_back(new Spectacle("Makbet", "2021-10-29", 10));
      spectacle.push_back(new Spectacle("Szalone nozyczki", "2021-10-12", 12));
      spectacle.push_back(new Spectacle("Pan Tadeusz", "2021-10-05", 23));
      spectacle.push_back(new Spectacle("Rome i Julia", "2021-10-02",25));
   }


   Database();
   ~Database();
};


#include "Database.h"

Database::Database()
{
   this->init();
}

Database::~Database()
{
   for(auto it : this->spectacle)
   {
      delete it;
   }
   this->spectacle.clear();
}
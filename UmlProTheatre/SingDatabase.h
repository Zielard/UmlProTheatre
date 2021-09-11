#pragma once
#include "Database.h"

static Database* s_instance;

class SingDatabase
{
public:
   static Database* getInstance()
   {
      if(nullptr == s_instance)
      {
         s_instance = new Database();
      }
      return s_instance;
   }

   ~SingDatabase()
   {
      if(nullptr != s_instance)
      {
         delete s_instance;
      }
   }
};


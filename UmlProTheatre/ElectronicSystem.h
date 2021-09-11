#pragma once
#include "CommonModule.h"
#include "Client.h"
#include "Database.h"
#include "Admin.h"

class ElectronicSystem
{
private:
   // create an empty structure (null)
   Client* client;
   Admin* admin;
public:
   
   ElectronicSystem()
   {
      client = new Client();
      admin = new Admin(client);
   }
   ~ElectronicSystem()
   {
      delete admin;
      delete client;
   }
   void runMain();
   void runClient();
   void runAdmin();
};


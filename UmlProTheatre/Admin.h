#pragma once
#include "Database.h"
#include "SingDatabase.h"
#include "Client.h"
class Admin
{
private:
   Client* client;
   Database* database;
public:

   Admin(Client * client)
   {
      this->client = client;
      this->database = SingDatabase::getInstance();
   }

   void addSpectacle();

   void cancelSpectacle();

   void editSpectacle();

   void applyPayment();

   void viewAllTickets();
};


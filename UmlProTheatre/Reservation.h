#pragma once
#include <string>

class Spectacle;

class Reservation
{

Spectacle* spectacle;
std::string clientFirstName;
std::string clientLastName;
std::string clientEmail;
bool isPaid;
bool isApproved;

public:

   Reservation(){}
   Reservation(std::string clientFirstName, std::string clientLastName, std::string clientEmail, Spectacle* spectacle)
   {
      this->clientFirstName = clientFirstName;
      this->clientLastName = clientLastName;
      this->clientEmail = clientEmail;
      this->spectacle = spectacle;
      this->isPaid = false;
      this->isApproved = false;
   };


   void setClientFirstName(std::string clientFirstName);
   std::string getClientFirstName();

   void setClientLastName(std::string clientFirstName);

   std::string getClientLastName();

   void setClientEmail(std::string clientEmail);

   std::string getClientEmail();

   void setPaid(bool flag);

   bool getPaid();

   void setApproved(bool flag);

   bool getApproved();

   void setSpectacle(Spectacle* spectacle);

   Spectacle* getSpectacle();
};


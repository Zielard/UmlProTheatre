#include "Spectacle.h"

void Spectacle::setName(std::string name)
{
   this->name = name;
}

std::string Spectacle::getName()
{
   return this->name;
}

void Spectacle::setDate(std::string date)
{
   this->date = date;
}

std::string Spectacle::getDate()
{
   return this->date;
}

void Spectacle::setnumberAll(int numberAll)
{
   this->numberAll = numberAll;
}

int Spectacle::getnumberAll()
{
   return this->numberAll;
}

void Spectacle::setnumberBuy(int numberBuy)
{
   this->numberBuy = numberBuy;
}

int Spectacle::getnumberBuy()
{
   return this->numberBuy;
}

std::vector<Reservation*>* Spectacle::getAllReservation()
{
   return this->reservation;
}

Reservation* Spectacle::makeReservation(std::string clientFirstName, std::string clientLastName, std::string clientEmail)
{
   Reservation* rv = nullptr;
   if((this->numberAll != this->numberBuy) && (this->numberAll > this->numberBuy))
   {
      this->numberBuy++;
      rv = new Reservation(clientFirstName, clientLastName, clientEmail, this);
      reservation->push_back(rv);
   }
   return rv;
}

void Spectacle::removeReservation(Reservation* rPointer)
{
   this->numberBuy--;
   this->reservation->erase(std::remove(reservation->begin(), reservation->end(), rPointer), reservation->end());
}


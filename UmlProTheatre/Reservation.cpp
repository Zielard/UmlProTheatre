#include "Reservation.h"
#include "spectacle.h"

void Reservation::setClientFirstName(std::string clientFirstName)
{
   this->clientFirstName = clientFirstName;
}

std::string Reservation::getClientFirstName()
{
   return this->clientFirstName;
}

void Reservation::setClientLastName(std::string clientFirstName)
{
   this->clientLastName = clientLastName;
}

std::string Reservation::getClientLastName()
{
   return this->clientLastName;
}

void Reservation::setClientEmail(std::string clientEmail)
{
   this->clientEmail = clientEmail;
}

std::string Reservation::getClientEmail()
{
   return this->clientEmail;
}

void Reservation::setPaid(bool flag)
{
   this->isPaid = flag;
}

bool Reservation::getPaid()
{
   return this->isPaid;
}

void Reservation::setApproved(bool flag)
{
   this->isApproved = flag;
}

bool Reservation::getApproved()
{
   return this->isApproved;
}

void Reservation::setSpectacle(Spectacle* spectacle)
{
   this->spectacle = spectacle;
}

Spectacle* Reservation::getSpectacle()
{
   return this->spectacle;
}
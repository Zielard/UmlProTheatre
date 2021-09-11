#include "Client.h"

void Client::buyTicket()
{
   std::cout << "Lista spektaklow (zakup) :" << std::endl;
   int index = 0;
   for(auto it : database->spectacle)
   {
      std::cout << index << ". Nazwa : " << it->getName()<< std::endl << "   Data : "<<it->getDate() << std::endl;
      index++;
   }

   std::cout << "-1. Anulowanie zakupu"<< std::endl;
   while(1)
   {
      int pos = 0;
      std::cout << "Ktory pozycje wybierasz?" << std::endl;
      std::cin >> pos;
      if(pos == -1)
      {
         std::cout << "Anulowano zakup" << std::endl;
         break;
      }
      try 
      {
         Spectacle* spectacleItem = database->spectacle.at(pos);
         Reservation* tempRes = spectacleItem->makeReservation(this->name, this->nazwisko, this->email);
         if(tempRes != nullptr)
         {
            this->clientReservation.push_back(tempRes);
            std::cout << "Udalo sie zrobic rezerwacje!" << std::endl;
            spectacleItem->CreateMessage("dalo sie zrobic rezerwacje! MSG!");
            bool flag;
            std::cout << "Czy chcesz teraz zaplacic? 0 - nie, 1 - tak" << std::endl;
            std::cin >> flag;
            if(flag == true)
            {
               tempRes->setPaid(true);
               std::cout << "Dokonano zaplaty" << std::endl;
            }
            this->addSubject(spectacleItem);
            break;
         }
         else
         {
            std::cout << "Nie ma juz wolnych miejsc" << std::endl;
         }
      }
      catch(const std::out_of_range& e) 
      {
         std::cout << "Zla pozycja (Poza zakresem)" << std::endl;
      }
   }
   system("pause");
}

void Client::cancelTicket()
{
   std::cout << "Lista twoich biletow (usuwanie) :" << std::endl;
   int index = 0;
   std::string msg = "";
   for(auto it : this->clientReservation)
   {
      std::cout << index <<". " << it->getSpectacle()->getName() << " " << it->getSpectacle()->getDate() << " Zaplacony : " << it->getPaid() << std::endl;
      index++;
   }
   while(1)
   {
      int pos = 0;
      std::cout << "Ktory pozycje wybierasz?" << std::endl;
      std::cin >> pos;

      try
      {
         Reservation* reservationItem = clientReservation.at(pos);
         reservationItem->getSpectacle()->removeReservation(reservationItem);
         clientReservation.erase(clientReservation.begin() + pos);

         msg = "Anulowano zakup ";
         msg += reservationItem->getSpectacle()->getName();
         msg += " z dnia " + reservationItem->getSpectacle()->getDate();
         this->RemoveFromTheList(reservationItem->getSpectacle(), msg);

         delete reservationItem;
         std::cout << "Udalo sie usunac bilet" << std::endl;
         break;
      }
      catch(const std::out_of_range& e)
      {
         std::cout << "Nie udalo sie odwolac biletu" << std::endl;
      }
   }
   system("pause");
}

void Client::payForTicket()
{
   std::cout << "Lista twoich biletow (zaplata) :" << std::endl;
   int index = 0;
   for(auto it : this->clientReservation)
   {
      std::cout << index << ". " << it->getSpectacle()->getName() << " " << it->getSpectacle()->getDate() << " Zaplacony : " << it->getPaid() << std::endl;
      index++;
   }

   std::cout << "Zakoncz - (-1)" << std::endl;
   while(1)
   {
      int pos = 0;
      std::cout << "Ktory pozycje wybierasz?" << std::endl;
      std::cin >> pos;

      if(pos == -1)
      {
         break;
      }
      try
      {
         Reservation* reservationItem = clientReservation.at(pos);
         if(reservationItem->getPaid() == true)
         {
            std::cout << "Ten bilet juz jest oplacony" << std::endl;
         }
         else
         {
            reservationItem->setPaid(true);
            std::cout << "Zaplacono za bilet!" << std::endl;
            break;
         }
      }
      catch(const std::out_of_range& e)
      {
         std::cout << "Nie udalo sie zaplacic za bilet" << std::endl;
      }
   }
   system("pause");
}

void Client::viewBill()
{
   int index = 0;
   std::cout << "Lista twoich biletow - (wyswietlanie) :" << std::endl;
   for(auto it : this->clientReservation)
   {
      std::cout << it->getSpectacle()->getName() << " " << it->getSpectacle()->getDate() << " Zaplacony : " << it->getPaid() << std::endl;
      index++;
   }
   system("pause");
}

void Client::viewMsg()
{
   std::cout << indexOfMsg << std::endl;
   system("pause");
}

std::vector<Reservation*>* Client::getClientReservationVec()
{
   return &clientReservation;
}
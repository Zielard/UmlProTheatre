#include "Admin.h"
#include "Reservation.h"
void Admin::addSpectacle()
{
   bool flag = true;
   std::cout << "Spektakle - (Dodawanie) :" << std::endl;

   Spectacle* spectacleItem = new Spectacle();
   while(flag)
   {
      try
      {
         int choose;
         std::string newName;
         std::string newDate;
         std::cout <<"Nazwa : " << spectacleItem->getName() << " " << spectacleItem->getDate()<< std::endl;
         std::cout << "Dodaj nazwe - 0 " << std::endl;
         std::cout << "Dodaj date - 1 " << std::endl;
         std::cout << "Zakoncz dodawanie - (-1)" << std::endl;
         std::cout << "Anuluj dodawanie - (-2)" << std::endl;
         std::cin >> choose;
         switch(choose)
         {
         case 0:
            std::cout << "Podaj nowa nazwe" << std::endl;
            std::cin >> newName;
            spectacleItem->setName(newName);
            break;
         case 1:
            std::cout << "Podaj nowa date" << std::endl;
            std::cin >> newDate;
            spectacleItem->setDate(newDate);
            break;
         case -1:
            std::cout << "Dodano nowy spektakl!" << std::endl;
            database->spectacle.push_back(spectacleItem);
            flag = false;
            break;
         case -2:
            std::cout << "Anulowamo dodawanie" << std::endl;
            flag = false;
            break;
         default:
            std::cout << "Nie ma takiej opcji" << std::endl;
            break;
         }
      }
      catch(const std::out_of_range& e)
      {
         std::cout << "Nie udalo sie usunac" << std::endl;
      }
   }
}

void Admin::cancelSpectacle()
{
   int index = 0;
   bool flag = true;
   std::cout << "Lista wszystkich spectaklow - (Usuwanie) :" << std::endl;
   for(auto it : this->database->spectacle)
   {
      std::cout << index << ". nazwa : " << it->getName() << "data " << it->getDate() << std::endl;
      index++;
   }

   int pos = 0;
   std::cout << "Ktora pozycje wybierasz?" << std::endl;
   std::cin >> pos;

   while(flag)
   {

      try
      {
         int choose;
         std::string msg = "";
         Spectacle* spectacleItem = this->database->spectacle.at(pos);
         std::vector<Reservation*>* rVector = spectacleItem->getAllReservation();
         std::vector<Reservation*>* cVector= client->getClientReservationVec();
         std::cout << "Napewno chcesz usnac? - (Usuwanie) :" << std::endl;
         std::cout << "Tak - 1" << std::endl;
         std::cout << "Nie - 0" << std::endl;
         std::cin >> choose;
         switch(choose)
         {
         case 0:
            flag = false;
            break;
         case 1:
            //remove from reservation in choose spectacle
            if(rVector != nullptr)
            {
               for(auto it : *rVector)
               {
                  it->setSpectacle(nullptr); 
                  it = nullptr;
                  //delete it;
               }
            }
            //                  cVector->erase(std::remove(cVector->begin(), cVector->end(), it), cVector->end());
            //remove from database spectacle list.
            std::remove(
               this->database->spectacle.begin(),
               this->database->spectacle.end(),
               spectacleItem);
            //remove form client list 
            if(cVector != nullptr)
            {
               for(auto it : *spectacleItem->getAllReservation())
               {
                  for(auto itt : *cVector)
                  {
                     if(it == itt)
                     {
                        cVector->erase(std::remove(cVector->begin(), cVector->end(), it), cVector->end());
                        delete it;
                     }
                  }
               }
            }

            msg = "Odwolano spektakl ";
            msg += spectacleItem->getName();
            msg += " z dnia " + spectacleItem->getDate();
            client->RemoveFromTheList(spectacleItem, msg);

            //delete pointer
            delete spectacleItem;
            flag = false;
            break;
         default:
            std::cout << "Nie ma takiej opcji" << std::endl;
            break;
         }
      }
      catch(const std::out_of_range& e)
      {
         std::cout << "Nie udalo sie usunac" << std::endl;
      }
   }
}

void Admin::editSpectacle()
{
   int index = 0;
   bool flag = true;
   std::cout << "Lista wszystkich spectaklow - (edytowanie) :" << std::endl;
   for(auto it : this->database->spectacle)
   {
      std::cout << index << ". nazwa : " << it->getName() << "data " << it->getDate() << std::endl;
      index++;
   }

   int pos = 0;
   std::cout << "Ktora pozycje wybierasz?" << std::endl;
   std::cin >> pos;

   while(flag)
   {

      try
      {
         int choose;
         std::string newName;
         std::string newDate;
         std::string msg = "";
         Spectacle* spectacleItem = this->database->spectacle.at(pos);
         std::cout << "Co chcesz edytowac - (edytowanie) :" << std::endl;
         std::cout << "Nazwe - 0" << std::endl;
         std::cout << "Date - 1" << std::endl;
         std::cout << "koniec edycji - (-1)" << std::endl;

         std::cin >> choose;
         switch(choose)
         {
         case 0:

            std::cout << "Podaj nowa nazwe" << std::endl;
            std::cin >> newName;
            msg = "Zmodyfikowano nazwe spektaklu! z ";
            msg += spectacleItem->getName();
            msg += " na " + newName;
            spectacleItem->setName(newName);
            spectacleItem->CreateMessage(msg);
            break;
         case 1:
            std::cout << "Podaj nowa date" << std::endl;
            std::cin >> newDate;
            msg = "Zmodyfikowano date spektaklu! z ";
            msg += spectacleItem->getDate();
            msg += " na " + newDate;
            spectacleItem->setDate(newDate);
            spectacleItem->CreateMessage(msg);
            break;
         case -1:
            flag = false;
            break;
         default:

            std::cout << "Nie ma takiej opcji" << std::endl;
            break;
         }
      }
      catch(const std::out_of_range& e)
      {
         std::cout << "Nie udalo sie edytowac biletu" << std::endl;
      }
   }
}

void Admin::applyPayment()
{
   //int index = 0;
   //bool flag = true;
   //std::cout << "Lista wszystkich biletow - (zatwierdzanie wplat) :" << std::endl;
   //for(auto it : this->database->spectacle)
   //{
   //   for(auto itt : *it->getAllReservation())
   //   {
   //      std::cout << index << ". Rezerwacja na : " << it->getName() << " " << it->getDate() << " Zaplacony : " << itt->getPaid() << std::endl;
   //      std::cout << "Zarezerwowany przez : " << itt->getClientFirstName() << " " << itt->getClientLastName() << std::endl;
   //      std::cout << std::endl;
   //      index++;
   //   }
   //}

   //int pos = 0;
   //std::cout << "Ktora pozycje wybierasz?" << std::endl;
   //std::cin >> pos;

   //while(flag)
   //{

   //   try
   //   {
   //      int choose;
   //      std::string newName;
   //      std::string newDate;
   //      std::string msg = "";
   //      Spectacle* spectacleItem = this->database->spectacle.at(pos);
   //      std::cout << "Napewno chcesz zatwierdzic - (edytowanie) :" << std::endl;
   //      std::cout << "Nie - 0" << std::endl;
   //      std::cout << "Tak - 1" << std::endl;
   //      std::cout << "koniec - (-1)" << std::endl;

   //      std::cin >> choose;
   //      switch(choose)
   //      {
   //      case 0:

   //         std::cout << "Podaj nowa nazwe" << std::endl;
   //         std::cin >> newName;
   //         msg = "Zmodyfikowano nazwe spektaklu! z ";
   //         msg += spectacleItem->getName();
   //         msg += " na " + newName;
   //         spectacleItem->setName(newName);
   //         spectacleItem->CreateMessage(msg);
   //         break;
   //      case 1:
   //         std::cout << "Podaj nowa date" << std::endl;
   //         std::cin >> newDate;
   //         msg = "Zmodyfikowano date spektaklu! z ";
   //         msg += spectacleItem->getDate();
   //         msg += " na " + newDate;
   //         spectacleItem->setDate(newDate);
   //         spectacleItem->CreateMessage(msg);
   //         break;
   //      case -1:
   //         flag = false;
   //         break;
   //      default:

   //         std::cout << "Nie ma takiej opcji" << std::endl;
   //         break;
   //      }
   //   }
   //   catch(const std::out_of_range& e)
   //   {
   //      std::cout << "Nie udalo sie edytowac biletu" << std::endl;
   //   }
   //}
}

void Admin::viewAllTickets()
{
   int index = 0;
   std::cout << "Lista wszystkich biletow - (wyswietlanie) :" << std::endl;
   for(auto it : this->database->spectacle)
   {
      it->getAllReservation();
      for(auto itt : *it->getAllReservation())
      {
         std::cout <<index <<". Rezerwacja na : "<< it->getName() << " " << it->getDate() << " Zaplacony : " << itt->getPaid() << std::endl;
         std::cout << "Zarezerwowany przez : " << itt->getClientFirstName() << " " << itt->getClientLastName() << std::endl;
         std::cout << std::endl;
         index++;
      }
   }
   system("pause");
}

#include "ElectronicSystem.h"

void ElectronicSystem::runMain()
{
   int choose = 0;
   while(1)
   {
      std::cout << "Wybierz opcje:" << std::endl;
      std::cout << "Klient - 0" << std::endl;
      std::cout << "Admin - 1" << std::endl;

      std::cin >> choose;
      switch(choose)
      {
      case 0:
         this->runClient();
         break;
      case 1:
         this->runAdmin();
         break;
      default:
         std::cout << "Nie ma takiej opcji" << std::endl;
         break;
      }
   }
   system("CLS");
}

void ElectronicSystem::runClient()
{
   int choose = 0;
   bool flag = true;
   while(flag)
   {
      std::cout << "Zalogowano jako Klient!" << std::endl;
      std::cout << "Wybierz opcje:" << std::endl;
      std::cout << "1.Kup bilet" << std::endl;
      std::cout << "2.Zaplac za bilet" << std::endl;
      std::cout << "3.Odwolaj zakup" << std::endl;
      std::cout << "4.Wyswietl kupione bilety" << std::endl;
      std::cout << "5.Wyswietl wiadomosci" << std::endl;
      std::cout << "6.Wyloguj" << std::endl;
      std::cin >> choose;

      switch(choose)
      {
      case 1:
         client->buyTicket();
         break;
      case 2:
         client->payForTicket();
         break;
      case 3:
         client->cancelTicket();
         break;
      case 4:
         client->viewBill();
         break;
      case 5:
         client->viewMsg();
         break;
      case 6:
         flag = false;
         break;
      default:
         std::cout << "Nie ma takiej opcji" << std::endl;
         break;
      }
      std::cout << std::endl;
      system("CLS");
   }
}

void ElectronicSystem::runAdmin()
{
   int choose = 0;
   bool flag = true;
   while(flag)
   {
      std::cout << "Zalogowano jako Admin!" << std::endl;
      std::cout << "Wybierz opcje:" << std::endl;
      std::cout << "1.Dodaj spektakl" << std::endl;
      std::cout << "2.Odwolaj spektakl" << std::endl;
      std::cout << "3.Edytuj spektakl" << std::endl;
      std::cout << "4.Wyswietl wszystkie rezerwacje" << std::endl;
      std::cout << "5.wyloguj" << std::endl;
      std::cin >> choose;

      switch(choose)
      {
      case 1:
         admin->addSpectacle();
         break;
      case 2:
         admin->cancelSpectacle();
         break;
      case 3:
         admin->editSpectacle();
         break;
      case 4:
         admin->viewAllTickets();
         break;
      case 5:
         flag = false;
         break;
      default:
         std::cout << "Nie ma takiej opcji" << std::endl;
         break;
      }
      std::cout << std::endl;
      system("CLS");
   }
}
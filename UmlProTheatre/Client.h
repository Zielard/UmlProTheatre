#pragma once
#include "SingDatabase.h"
#include "Observer.h"

static int static_number_ = 0;

class Client : public IObserver {

private:
   std::string name;
   std::string nazwisko;
   std::string email;
   Database* database;
   std::vector<Reservation*> clientReservation;
   std::vector<Spectacle*> clientObserver;

   //for observeration
   std::string indexOfMsg = "";
   std::string message_from_subject_;
   int number_;

public:

   Client()
   {
      this->name = "Jan";
      this->nazwisko = "Kowalski";
      this->email = "Kowalski@wp.pl";
      this->database = SingDatabase::getInstance();
   }

   void buyTicket();

   void cancelTicket();

   void payForTicket();

   void viewBill();

   void viewMsg();

   std::vector<Reservation*>* getClientReservationVec();

   //FOR OBSERWATION
   void addSubject(Spectacle* subject_)
   {
      //dodanie do listy i rozpoczecie subskrybcji
      clientObserver.push_back(subject_);
      subject_->Attach(this);
   }

   void Update(const std::string& message_from_subject) override
   {
      message_from_subject_ = message_from_subject;
      AddInfo();
   }

   void RemoveFromTheList(Spectacle* subject_ , const std::string& message_from_subject) 
   {

      if(std::find(clientObserver.begin(), clientObserver.end(), subject_) != clientObserver.end())
      {
         this->clientObserver.erase(std::remove(clientObserver.begin(), clientObserver.end(), subject_), clientObserver.end());
         message_from_subject_ = message_from_subject;
         subject_->Detach(this);
         AddInfo();
      }
   }

   void AddInfo() 
   {
      indexOfMsg += this->message_from_subject_;
      indexOfMsg += "\n";
   }
};


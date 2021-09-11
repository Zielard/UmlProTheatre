#pragma once
#include "CommonModule.h"
#include "Reservation.h"
#include "Observable.h"
#include <vector>
#include <list>
class Spectacle : public Observable {

private:

std::string name;
std::string date;
int numberAll;
int numberBuy;

std::vector<Reservation*> *reservation;

public:

   Spectacle() 
   {
      this->name = "NewName";
      this->date = "NewDate";
   };
   Spectacle(std::string name, std::string date, int numberAll)
   {
      reservation = new std::vector<Reservation*>;
      this->name = name;
      this->date = date;
      this->numberAll = numberAll;
   }


   void setName(std::string name);
   std::string getName();

   void setDate(std::string date);
   std::string getDate();

   void setnumberAll(int numberAll);
   int getnumberAll();
   
   void setnumberBuy(int numberBuy);
   int getnumberBuy();

   Reservation* makeReservation(std::string clientFirstName,std::string clientLastName,std::string clientEmail);

   void removeReservation(Reservation* rPointer);

   std::vector<Reservation*>* getAllReservation();



    /**
    * The subscription management methods.
    */
   void Attach(IObserver* observer) override {
      list_observer_.push_back(observer);
   }
   void Detach(IObserver* observer) override {
      list_observer_.remove(observer);
   }
   void Notify() override {
      std::list<IObserver*>::iterator iterator = list_observer_.begin();
      //HowManyObserver();
      while(iterator != list_observer_.end()) {
         (*iterator)->Update(message_);
         ++iterator;
      }
   }

   void CreateMessage(std::string message = "Empty") 
   {
      this->message_ = message;
      Notify();
   }
   void HowManyObserver() 
   {
      std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
   }

   /**
    * Usually, the subscription logic is only a fraction of what a Subject can
    * really do. Subjects commonly hold some important business logic, that
    * triggers a notification method whenever something important is about to
    * happen (or after it).
    */
   void SomeBusinessLogic() {
      this->message_ = "change message message";
      Notify();
      std::cout << "I'm about to do some thing important\n";
   }

private:
   std::list<IObserver*> list_observer_;
   std::string message_;
};
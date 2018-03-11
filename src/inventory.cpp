#include "inventory.h"

void Inventory::addItem(Movie* arg){
  this->contents->enroll(arg->getTitle() + arg->getYear(), *arg);
}

Movie Inventory::getItem(string title, string year){
  this->contents->get(title+year);
}
void Inventory::addItem(Movie* arg){
  this->contents->enroll(arg->getTitle() + arg->getYear(), *arg);
}

Movie Inventory::getItem(string title, string year, string director, string actor){
  this->contents->get(title+year+director+actor);
}

bool Inventory::newTransaction(string customer, string title, string year, string director, string actor){

  Movie m = this->getItem(title, year, director, actor);

  if(isMovieCheckedOut(m)){
    return false;
  }

  vector<Transaction>* b = *(this->transactionLog->get(getClient(customer)));

  Transaction *t = new Transaction();
  t->addMovie(m);
  b->push_back(*t);
}

void Inventory::addClient(Client c){
  this->clientelle.push_back(c);
}

Client Inventory::getClient(string c){
  for(Client i : this->clientelle){
    if(i.getName() == c){
      return i;
    }
  }
}

void Inventory::printAllMedia(){

}

bool Inventory::isMovieCheckedOut(Movie arg){
  for(Client c : clientelle){

    vector<Transaction>* log = *transactionLog->get(c);

    for(Transaction t : *log){
      if(t.contains(arg) && t.isReturned == false){
        return true;
      }
    }
  }

  return false;
}

bool Inventory::returnItem(string title, string year, string director, string actor){
  Movie a = getItem(title, year, director, actor);

  for(Client c : clientelle){
    for(Transaction t : **transactionLog->get(c)){
      if(t.contains(a) && t.isReturned == false){
        t.isReturned = true;
        return true;
      }
    }
  }

  return false;
}

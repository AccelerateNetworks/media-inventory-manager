#include "inventory.h"

void Inventory::addItem(Movie* arg){
  this->contents->enroll(arg->getTitle() + arg->getYear(), *arg);
}

Movie Inventory::getItem(string title, string year){
  this->contents->get(title+year+director+actor);
}

bool Inventory::newTransaction(string customer, string title, string year, string director, string actor){

  Movie m = this->getItem(title, year, director, actor);

  if(isMovieCheckedOut()){
    return false;
  }

  vector<Transaction>* b = *(this->transactionLog->get(getClient(customer)));
  b->push_back(new Transaction());
}

void Inventory::addClient(Client c){
  this->clientelle.push_back(c);
}

void Inventory::getClient(string c){
  for(Client i : this->clientelle){
    if(i.getName() == c){
      return i;
    }
  }
}

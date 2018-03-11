#include "inventory.h"



/** Add an item to the contents hashmap
 *
 * @param arg a Movie pointer to the movie object we want to add to the
 * contents hashmap
 */
void Inventory::addItem(Movie* arg){
  this->contents->enroll(arg->getTitle() + arg->getYear(), *arg);
}

/**
 *
 * @param title
 * @param year
 * @return
 */
Movie Inventory::getItem(const string &title, const string &year){
  return *(this->contents->get(title+year));
}

/**
 *
 * @param title
 * @param year
 * @param director
 * @param actor
 * @return
 */
Movie Inventory::getItem(const string &title, const string &year,
                         const string &director, const string &actor){
  return *(this->contents->get(title+year+director+actor));
}

/**
 *
 * @param customer
 * @param title
 * @param year
 * @param director
 * @param actor
 * @return
 */
bool Inventory::newTransaction(const string &customer, const string &title,
                               const string &year, const string &director,
                               const string &actor){

  Movie m = this->getItem(title, year, director, actor);

  if(isMovieCheckedOut(m)){
    return false;
  }

  vector<Transaction>* b = *(this->transactionLog->get(getClient(customer)));

  Transaction *t = new Transaction();
  t->addMovie(m);
  b->push_back(*t);
}

/**
 *
 * @param c
 */
void Inventory::addClient(Client &c){
  this->clientelle.push_back(c);
}

/**
 *
 * @param c
 * @return
 */
Client Inventory::getClient(const string &c){
  for(Client i : this->clientelle){
    if(i.getName() == c){
      return i;
    }
  }
}

/**
 *
 */
void Inventory::printAllMedia(){

}

/**
 *
 * @param arg the movie object reference we are going to look for
 * @return
 */
bool Inventory::isMovieCheckedOut(Movie arg){
  for(Client& c : clientelle){

    for(Transaction& t : **transactionLog->get(c)){
      if(t.contains(arg) && !t.isReturned ){
        return true;
      }
    }
  }
  return false;
}

/**
 *
 * @param title : string
 * @param year : string
 * @param director :
 * @param actor : string
 * @return
 */
bool Inventory::returnItem(const string &title, const string &year,
                           const string &director, const string &actor){
  Movie a = getItem(title, year, director, actor);
  // by setting c as a reference, we can manipulate the contents of clientelle
  for(Client& c : clientelle){
    // t is a reference so that we can manipulate the contents of translog
    for(Transaction& t : **transactionLog->get(c)){
      if(t.contains(a) && !t.isReturned){
        
        return (t.isReturned = true); // assignment is intentional, don't change
      }
    }
  }
  return false;
}

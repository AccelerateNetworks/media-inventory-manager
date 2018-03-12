#ifndef WHOOT
#define WHOOT

#include "inventory.h"
#include <iostream>

/** Add an item to the contents hashmap
 *
 * @param arg a Movie pointer to the movie object we want to add to the
 * contents hashmap
 */
void Inventory::addItem(Movie* arg){
  vector<Movie>** v = this->contents->get(arg->getTitle() +
                                          arg->getYear() +
                                          arg->getDirector() +
                                          arg->getActor());
  if(v == nullptr){

    vector<Movie>* n = new vector<Movie>();
    n->push_back( *(arg) ); //make a copy that wont be deallocated
    this->contents->enroll(arg->getTitle() +
                           arg->getYear() +
                           arg->getDirector() +
                           arg->getActor(), n);
  } else {
    (*v)->push_back( *(arg) );
    this->contents->enroll(arg->getTitle() +
                           arg->getYear() +
                           arg->getDirector() +
                           arg->getActor(), *v);
  }
}

/**
 *
 * @param title
 * @param year
 * @param director
 * @param actor
 * @return
 */
void Inventory::getFreeCopy(const string &title, const string &year,
                              const string &director, const string &actor, Movie* ptr){

  ptr = nullptr;

  if(this->contents->get(title+year+director+actor) == nullptr){
    ptr = nullptr;
    return;
  }
  vector<Movie>* v = *this->contents->get(title+year+director+actor);
  if(v == nullptr) {
    std::cout << "LINE 49 ERROR WOW" << std::endl;
    ptr = nullptr;
    
  }

  for(Movie m : *v){
    if(!isMovieCheckedOut(m)){
      ptr = &m;
    }
  }
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

  Movie* m;
  getFreeCopy(title, year, director, actor, m);
  if(m == nullptr) return false;

  Transaction* t = new Transaction();
  t->addMovie(m);
  vector<Transaction>* b = *(this->transactionLog->get(getClient(customer)));
  b->push_back(*t);
  this->transactionLog->enroll(getClient(customer), b);
  return true;
}

/**
 *
 * @param c
 */
void Inventory::addClient(Client &c){
  this->clientelle.push_back(c);
  this->transactionLog->enroll(c, new vector<Transaction>);
}

/**
 *
 * @param c the string representing a client's space seperated first then
 * last name.
 * @return returns a copy of the client object
 */
Client Inventory::getClient(const string &c){
  for(Client& i : this->clientelle){
    if(i.getName() == c){
      return i;
    }
  }
  throw "Internal Logic Error: Inventory::addClient(Client &c)";
}

/**
 *
 */
void Inventory::printAllMedia(){

}

/**
 *
 * @param target the movie object reference we are going to look for
 * @return a bool indicating if we succesfully found the target movie
 */
bool Inventory::isMovieCheckedOut( Movie &target){
  for(Client& c : clientelle){
    for(Transaction& t : **transactionLog->get(c)){
      if(t.contains(target) && !t.isReturned ){
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
bool Inventory::returnItem(Movie m){
  // by setting c as a reference, we can manipulate the contents of clientelle
  for(Client& c : clientelle){
    // t is a reference so that we can manipulate the contents of translog
    for(Transaction& t : **transactionLog->get(c)){
      if(t.contains(m) && !t.isReturned){
        return (t.isReturned = true); // assignment is intentional, don't change
      }
    }
  }
  return false;
}

bool Inventory::returnItem(int id) {
  return false;
}

#endif

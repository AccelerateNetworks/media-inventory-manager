#ifndef INV_H
#define INV_H

#include <string>
#include <vector>
#include <iostream>
using std::string;
using std::vector;

#include "hashtable.h"
#include "client.h"
#include "movie.h"
#include "transaction.h"

/**
 *
 * @param arg the string representation of the Media object's title
 * @return
 */
int hash(const string& arg){
  return (int) arg[0];
}

int hashc(const Client& c){
  return (int) c.getName()[0];
}

class Inventory {
  HashTable<string, Movie>* contents{ new HashTable<string, Movie>(hash)};
  HashTable<Client, vector<Transaction>*>* transactionLog
                 {new HashTable<Client, vector<Transaction>*>(hashc)};
  vector<Client> clientelle{};
  Client getClient(const string &name);

 public:
  
  // empty ctor to handle non-trivial member variable instantiation.
  Inventory() = default;
  
  
  void addItem(Movie*);
  
  /**
   *
   * @param title
   * @param year
   * @param director
   * @param actor
   * @return
   */
  Movie getItem(const string &title, const string &year, const string &director,
                const string &actor);
  
  /**
   *
   * @param title
   * @param year
   * @param director
   * @param actor
   * @return
   */
  bool returnItem(const string &title, const string &year,
                  const string &director, const string &actor);
  
  /**
   *
   * @param customer
   * @param title
   * @param year
   * @param director
   * @param actor
   * @return
   */
  bool newTransaction(const string &customer, const string &title,
                      const string &year, const string &director,
                      const string &actor);
  
  /**
   *
   * @param c
   */
  void addClient(Client &c);
  
  /**
   *
   */
  void printAllMedia();

/**
 *
 * @param arg the movie object reference we are going to look for
 * @return
 */
  bool isMovieCheckedOut(Movie arg);


  ~Inventory();
  
  /**
   *
   * @param title
   * @param year
   * @return
   */
  Movie getItem(const string &title, const string &year);
};

#endif // INV_H

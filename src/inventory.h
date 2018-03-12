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


class Inventory {

  static int hashs(const string& arg){
    return (int) arg[0];
  }

  static int hashc(const Client& c){
    return (int) c.getName()[0];
  }

  HashTable<string, vector<Movie>*>* contents
    = new HashTable<string, vector<Movie>*>(hashs);
  HashTable<Client, vector<Transaction>*>* transactionLog
    = new HashTable<Client, vector<Transaction>*>(hashc);
  vector<Client> clientelle{};
  Client getClient(const string &name);

 public:

  // empty ctor to handle non-trivial member variable instantiation.
  Inventory() = default;

  void addItem(Movie);
  Movie getItem(int id);

  /**
   * @param title
   * @param year
   * @param director
   * @param actor
   * @return
   */
  Movie& getFreeCopy(const string &title, const string &year,
                    const string &director, const string &actor);

  /**
   *
   * @param id
   * @return
   */
  bool returnItem(int id);

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
 * @param target the movie object reference we are going to look for
 * @return
 */
  bool isMovieCheckedOut( Movie &target);


  //~Inventory();


  /**
   *
   * @param m
   * @return
   */
  bool returnItem(Movie m);
};

#endif // INV_H

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
  Client getClient(string name);

 public:
  
  // empty ctor to handle non-trivial member variable instantiation.
  Inventory() = default;
  
  
  void addItem(Movie*);
  Movie getItem(string, string, string, string);
  bool returnItem(string, string, string, string);
  bool newTransaction(string, string, string, string, string);
  void addClient(Client);
  void printAllMedia();
  bool isMovieCheckedOut(Movie);


  ~Inventory();
  
  Movie getItem(string title, string year);
};

#endif // INV_H
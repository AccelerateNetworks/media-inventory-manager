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

int hash(string arg){
  return (int) arg[0];
}

int hashc(Client c){
  return (int) c.getName()[0];
}

class Inventory {
  HashTable<string, Movie>* contents = new HashTable<string, Movie>(hash);
  HashTable<Client, vector<Transaction>*>transactionLog(hashc);
  vector<Client> clientelle;
  Client getClient(string name);

 public:
  void addItem(Movie*);
  Movie getItem(string, string);
  Movie getItem(string, string, string, string);
  bool returnItem(string, string);
  bool returnItem(string, string, string, string);
  void newTransaction(string, string, string, string);
  void addClient(Client);
  void printAllMedia();
  bool isMovieCheckedOut(Movie);


  ~Inventory();
};

#endif // INV_H

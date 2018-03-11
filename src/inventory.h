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

class Inventory {
  HashTable<string, Movie>* contents = new HashTable<string, Movie>(hash);
  HashTable<string, Client>* clientelle;
  vector<Transaction> transactionLog;

 public:
  void addItem(Movie*);
  Movie getItem(string, string);
  void newTransaction(string, string, string);
  void addClient(Client);
  void printAllMedia();
};

#endif // INV_H

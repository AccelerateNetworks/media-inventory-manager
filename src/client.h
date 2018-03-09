#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
using std::string;
using std::ostream;

class Client {

  int id;
  string firstName, lastName;

  static int GET_NEXT_ID();

 public:
  static int NEXT_ID;
  Client(string, string);
  string hash();
  string getName();
  int getID();
  bool operator<(Client);
  bool operator>=(Client);
  ostream& operator<<(ostream&);
};

#endif // CLIENT_H

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
  
  string comparableName()const;

 public:
  static int NEXT_ID;
  Client(string, string);
  string hash();
  string getName()const;
  int getID()const;
  bool operator<(const Client &)const;
  bool operator>=(Client)const;
  ostream& operator<<(ostream&);
};

#endif // CLIENT_H

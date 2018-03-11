#include "client.h"

int Client::NEXT_ID = 0;

Client::Client(string first, string last){
  this->id = Client::GET_NEXT_ID();
  this->firstName = first;
  this->lastName = last;
}

int Client::GET_NEXT_ID(){
  return Client::NEXT_ID++;
}

int Client::hash(){
  return (int) this->firstName[0];
}

int Client::getID() const {
  return this->id;
}

bool Client::operator<(const Client& c) const {
  bool b = true;
  int least = (int)((this->comparableName().length()<=c.comparableName().length())?
              this->comparableName().length():c.comparableName().length());
  int i = 0;
  for(; i < least && b ;  ++i){
    // starting out, iterate over char arrays until left != right;
    // after the first instance of != return the result of:
    //        (true if <; and false if >)
    b= this->getName()[i] == c.getName()[i];
  }
  return i < least && this->getName()[i] < c.getName()[i];
}

bool Client::operator>=(Client c) const {
  return !(this->operator<(c));
}

ostream& Client::operator<<(ostream& out){
  out << this->id << ": " << this->getName();
  return out;
}

string Client::getName()const {
  return this->firstName + " " + this->lastName;
}

string Client::comparableName() const {
  return this->firstName + this->lastName;
}

bool operator==(const Client& l, const Client& r) {
  return l.getName() == r.getName();
}

bool operator!=(const Client &l, const Client &r)  {
  return !(l == r);
}

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

string Client::hash(){
  return std::to_string( this->firstName[0] + this->lastName[0]  );
}

int Client::getID(){
  return this->id;
}

bool Client::operator<(Client c){
  for(int i = 0; i < this->getName().length() && i < c.getName().length(); ++i){
    bool b = this->getName()[i] < c.getName()[i];
    if(b) return true;
    if(this->getName()[i] > c.getName()[i]) return false;
  }

  return false;
}

bool Client::operator>=(Client c){
  return !(this->operator<(c));
}

ostream& Client::operator<<(ostream& out){
  out << this->id << ": " << this->getName();
  return out;
}

string Client::getName(){
  return this->firstName + " " + this->lastName;
}



#include "../src/client.h"

#include <string>
#include <iostream>

using std::cout;
using std::endl;

extern Client globalClientOne("Sarah", "Anderson");
extern Client globalClientTwo("Phillip", "Comstock");

void clientIDTests();
void clientNameTests();
void clientSortTests();

void runClientTests(){
  try{
    clientIDTests();
      cout << "[+] Passed Client ID Tests" << endl;
    clientNameTests();
    cout << "[+] Passed Client name tests" <<endl;
    clientSortTests();
    cout << "[+] Passed CLient sort tests" << endl;
  }catch(const char* c){
    cout << "[-] Client Error: " << c << endl;
  }
}

void clientIDTests(){

  if(globalClientOne.getID()!= 0) throw "client ID not starting at 0";
  if(globalClientTwo.getID()!= 1) throw "client ID not incrementing by one";
  if(Client::NEXT_ID != 2) throw "client ID not string ID Correctly";

}

void clientNameTests(){
  if(globalClientOne.getName() != "Sarah Anderson") throw "names borked yo";
}

void clientSortTests(){
  if(globalClientTwo < globalClientOne)throw "Sort Comarator failed!";
}


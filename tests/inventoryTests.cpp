#ifndef INVTEST
#define INVTEST

#include "../src/inventory.h"

class Client;
class Movie;

#include <iostream>
using std::cout;
using std::endl;

 Inventory testInv;
 Movie testMov("1", "1", "1", "1");
 Movie testMov2("1", "1", "1", "1");
 Movie testMov3("3", "3", "3", "3");

void preTestSetup(){
  testInv.addItem(testMov);
  testInv.addItem(testMov2);
  testInv.addItem(testMov3);

  Client tc = Client("Rita","TestyBoy");
  testInv.addClient(tc);
}

void inventoryEnrollTest(){
  bool b;

  b = testInv.newTransaction("Rita TestyBoy", "1", "1", "1", "1");
  if(!b) throw "failed first checkout EnrollTest";
  if(!testInv.isMovieCheckedOut(testMov) && !testInv.isMovieCheckedOut(testMov2))
    throw "Movies arent actualy being checked out!";

  b = testInv.newTransaction("Rita TestyBoy", "1", "1", "1", "1");
  if(!b) throw "Failed second enrollment EnrollTest";

  b = testInv.newTransaction("Rita TestyBoy", "1", "1", "1", "1");
  if(b) throw "checked out too many testmovie! enrolltest";

  testInv.newTransaction("Rita TestyBoy", "3", "3", "3", "3");
  b = testInv.returnItem(testMov);
  if(!b) throw "returning movie returned false!";
  b = testInv.newTransaction("Rita TestyBoy", "3", "3", "3", "3");
  if(!b) throw "Movie not returned right, cannot be checked back out!";
}

void inventoryTests(){

  cout << "[+] Beginning Inventory Tests" << endl;
  preTestSetup();
  try{
    inventoryEnrollTest();
      cout << "[+] Passed Tests" << endl;
  } catch (const char* c) {
    cout << "[-] Failed: " << c << endl;
  }
}

#endif //TESTINV

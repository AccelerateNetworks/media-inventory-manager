#include "../src/inventory.h"
#include "../src/movie.h"
#include "../src/client.h"

#include <iostream>
using std::cout;
using std::endl;

extern Inventory testInv;
extern Movie testMov("1", "1", "1", "1");
extern Movie testMov2("1", "1", "1", "1");
extern Movie testMov3("3", "3", "3", "3");

void preTestSetup(){
  testInv.addItem(testMov);
  testInv.addItem(testMov2);
  testInv.addItem(testMov3);

  testInv.addClient(Client("Rita","TestyBoy"));
}

void inventoryEnrollTest(){
  bool b;

  b = testInv.newTransaction("Rita TestyBoy", "1", "1", "1", "1");
  if(!b) throw "failed first checkout EnrollTest";

  b = testInv.newTransaction("Rita TestyBoy", "1", "1", "1", "1");
  if(!b) throw "Failed second enrollment EnrollTest";

  b = testInv.newTransaction("Rita TestyBoy", "1", "1", "1", "1");
  if(b) throw "checked out too many testmovie! enrolltest";

  testInv.newTransaction("Rita TestyBoy", "3", "3", "3", "3");
  b = testInv.returnItem(testMov.getId());
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

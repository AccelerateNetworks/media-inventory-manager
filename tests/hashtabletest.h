#include <iostream>
#include <string>
#include <utility>
#include "../src/hashtable.h"
using namespace std;

int intHasher(int arg){
  return arg % 3;
}
extern HashTable<int,int> testTable(&intHasher);

void hashTableEnrollTest();
void hashTableConstructorTest();
void hashTableTest(){
  cout << "[+] Testing HashTable" << endl;
  try{
    hashTableConstructorTest();
    cout << "[+] Passed constructor test" << endl;
    hashTableEnrollTest();
    cout << "[+] Passed enroll test" << endl;
  } catch (const char* s){
    cout << "[-] " << s << endl;
  }

}

void hashTableConstructorTest(){
  if(testTable.getNumberOfEntries() != 0) throw "Error: hashtable constructor failed test 1";
  if(testTable.getHash(33) != 0) throw "Error: hashtable constructor failed test 2";
}

void hashTableEnrollTest(){
  try{
    testTable.enroll(2, 4);
    if(testTable.get(2)!=4){
      throw "Failed enroll test at first get()";
    }
    testTable.enroll(2, 5);
    if(testTable.get(2)!=5){
      throw "Failed enroll test at second get()";
    }
    if(testTable.getNumberOfEntries() != 1)
      throw "Failed enroll test, number of entries not updated on enroll";

  } catch (const char* s){
    throw s;
  }
}

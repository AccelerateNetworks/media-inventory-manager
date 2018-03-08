

#ifndef MEDIA_INVENTORY_MANAGER_HASHTABLETEST_H
#define MEDIA_INVENTORY_MANAGER_HASHTABLETEST_H

#include <iostream>
#include <string>
#include "hashtable.h"
using namespace std;

int intHasher(int arg){
  return arg % 3;
}
extern HashTable<int,int> testTable(&intHasher);

void hashTableConstructorTest();
void hashTableTest(){
  cout << "[+] Testing HashTable" << endl;
  try{
    hashTableConstructorTest();
    cout << "[+] Passed constructor test" << endl;
  } catch (string s){
    cout << "[-] " << s << endl;
  }
  
}

void hashTableConstructorTest(){
  if(testTable.getNumberOfEntries() != 0) throw "Error: hashtable constructor failed test 1";
  if(testTable.getHash(33) != 0) throw "Error: hashtable constructor failed test 2";
}


#endif //MEDIA_INVENTORY_MANAGER_HASHTABLETEST_H

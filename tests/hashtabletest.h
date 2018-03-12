#ifndef HASTHTABLETEST_H
#define HASTHTABLETEST_H


#include <iostream>
#include <string>
#include <utility>
#include "../src/hashtable.h"
using namespace std;

int intHasher(const int& arg){
  return arg % 3;
}
//extern HashTable<int,int> testTable(&intHasher); // NOLINT
HashTable<int,int> testTable(&intHasher); // NOLINT

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

void hastablesortingTest(){
  int a[20] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  HashTable<int,int> sortableTable(intHasher);
  try{
    testTable.enroll(2, 4);
    a = testTable.get(2);
    if(a == nullptr){
      throw "Failed enroll test at first get(): returned nullptr";
    }
    if(*a != 4) throw "failed enroll test at first get(): wrong val";

    testTable.enroll(2, 5);
    if(*testTable.get(2)!=5){
      throw "Failed enroll test at second get()";
    }
    if(testTable.getNumberOfEntries() != 1)
      throw "Failed enroll test, number of entries not updated on enroll";

  } catch (const char* s){
    throw s;
  }
}

void hashTableConstructorTest(){
  if(testTable.getNumberOfEntries() != 0) throw "Error: hashtable constructor failed test 1";
  if(testTable.getHash(33) != 0) throw "Error: hashtable constructor failed test 2";
}

void hashTableEnrollTest(){
  int* a;

  try{
    testTable.enroll(2, 4);
    a = testTable.get(2);
    if(a == nullptr){
      throw "Failed enroll test at first get(): returned nullptr";
    }
    if(*a != 4) throw "failed enroll test at first get(): wrong val";

    testTable.enroll(2, 5);
    if(*testTable.get(2)!=5){
      throw "Failed enroll test at second get()";
    }
    if(testTable.getNumberOfEntries() != 1)
      throw "Failed enroll test, number of entries not updated on enroll";

  } catch (const char* s){
    throw s;
  }
}


#endif //HASTHTABLETEST_H

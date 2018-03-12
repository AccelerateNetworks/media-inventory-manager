// dependencies
#include <iostream>
#include <iomanip>
#include <utility>
#include <chrono>
#include <ctime>

// test files
#include "transactiontest.h"
#include "movietest.h"
#include "hashtabletest.h"
#include "clientTests.cpp"
#include "inventoryTests.cpp"

using namespace std;


/**
 *
 * @return
 */
int main() {
  
  time_t t = chrono::system_clock::to_time_t(chrono::system_clock::now());
  string s = ctime(&t);
  cout << s << endl;
  
  cout << "[+] Running all tests -" << endl;
  cout << "[+]\t\t hashTable testing START" << endl;
  hashTableTest();
  cout << "[+]\t\t hashTable testing END" << endl;
  
  cout << endl;
  
  cout << "[+]\t\t class Movie testing START" << endl;
  // the bool parameter is used to toggle verbose  mode of test functions
  movie_test::movie_testing(false); // try/catch block is inside this function
  cout << "[+]\t\t class Movie testing END" << endl;
  
  cout << endl;
  
  cout << "[+]\t\t class Transaction testing START" << endl;
  // the bool parameter is used to toggle verbose  mode of test functions
  transaction_test::test_transaction(false); // try/catch block is inside this function
  cout << "[+]\t\t class Transaction testing END" << endl;
  
  cout << endl;

  cout << "[+]\t\t class Client testing START" << endl;
  runClientTests();
  cout << "[+]\t\t class Client testing END" << endl;

  cout << "[+]\t\t class Inventory testing START" << endl;
  inventoryTests();
  cout << "[+]\t\t class Inventory testing END" << endl;
  return 0;
}

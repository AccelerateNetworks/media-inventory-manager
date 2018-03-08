#include <iostream>
#include <iomanip>
#include <utility>
#include "movietest.h"
#include "hashtabletest.h"

using namespace std;


/**
 *
 * @return
 */
int main() {

  cout << "[+] Running all tests -" << endl;
  cout << "\t\t hashTable testing START" << endl;
  hashTableTest();
  cout << "\t\t hashTable testing END" << endl;

  cout << "\t\t class Movie testing START" << endl;
  // the bool parameter is used to toggle verbose  mode of test functions
  movie_testing(false); // try/catch block is inside this function
  cout << "\t\t class Movie testing END" << endl;

  return 0;
}

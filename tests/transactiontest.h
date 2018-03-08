
#ifndef MEDIA_INVENTORY_MANAGER_TRANSACTIONTEST_H
#define MEDIA_INVENTORY_MANAGER_TRANSACTIONTEST_H
#include <iostream>
#include <iomanip>
#include <utility>
#include "../src/transaction.h"


using namespace std;
/*
 longest_string_length is used in formatting output of the test functions to
 ensure that we get more readable output from pass/fail reports.
*/
int longest_string_length = 48;

/*
 pf is used to set a minimum width for our pass/fail outputs for more
 readable output from pass/fail reports.
 */
int pf = 20;

/**
 *
 * @param testName
 * @param testNameLen
 */
void test_passed_output(const string &testName) {
  int l = longest_string_length;
  cout << left << setw(pf) << "[+] passed" << left << ":" << setw(l)
       << right
       << testName << endl;
}

/**
 *
 * @param testName
 * @param testNameLen
 */
void test_failed_outptut(const string &testName) {
  int l = longest_string_length;
  cout << left << setw(pf)  << "[-] failed" << left << ":" << setw(l) <<
       right
       << testName << endl;
}


/*


Transaction() = default;

bool isDue()const;
uint64_t unixTimeCheckedOut()const;
bool contains(const Movie& arg)const;
std::vector<Movie> getContents();

 */


/**
 *
 * @param be_verbose a bool that we can use to toggle output describing each
 *                   individual test case being conducted
 * @return a boolean value stating if the test failed or if it threw an error
 */
bool test_transaction_constructor_implementation(const bool &be_verbose){
  
  bool all_tests_passed = true;
  
  if(be_verbose) {
    cout << "[+] test Transaction construction for class Transaction" << endl;
  }
  try {
    Transaction t(1);
  
    Transaction tt();
  }catch (std::exception e){
    all_tests_passed = false;
  }
  try {
    Transaction t(0);
    all_tests_passed = false; // if we get passed Transaction
  }catch (std::exception e){ }
  
  return true;
};

bool test_transaction_isDue_function_implementation(const bool &be_verbose,
                                                    Transaction t){
  if(be_verbose) {
    cout << "[+] test Transaction::isDue() function for class Transaction"
         << endl;
  }
  try {
    t.isDue();
  }catch (std::exception e){
    return false;
  }
  return true;
}

/**
 *      * the first try/catch block handles testing the Transaction
 *      constructor's empty default implementation.
 *
 * @param be_verbose a bool that we can use to toggle output describing each
 *                   individual test case being conducted
 * @return a boolean value stating if the test failed or if it threw an error
 */
bool test_transaction(const bool& be_verbose){
  
  bool all_passed = true;
  
  // alias to just x in order to keep code more readable.
  int x = longest_string_length;
  
  
  std::string funcName = "test_transaction_constructor_implementation";
  // testing the Transaction constructor as an independent object.
  cout << left << setw(pf) << "[+] performing test" << left << ":"
       << setw(x) << right << funcName
       << endl;
  if(test_transaction_constructor_implementation(be_verbose)){
    test_passed_output(funcName);
  
    // if the ctor test has succeeded, we are safe to proceed with all other
    // function tests for Transaction.
    
    Transaction t();
    
    funcName = "test_transaction_isDue_function_implementation";
    // testing the Transaction constructor as an independent object.
    cout << left << setw(pf) << "[+] performing test" << left << ":"
         << setw(x) << right << funcName
         << endl;
    if(test_transaction_isDue_function_implementation(be_verbose, t)){
      test_passed_output(funcName);
    }else {
      test_failed_outptut(funcName);
      all_passed = false;
    }
    
  }else {
    test_failed_outptut(funcName);
    all_passed = false;
  }
  return all_passed;
}



#endif //MEDIA_INVENTORY_MANAGER_TRANSACTIONTEST_H

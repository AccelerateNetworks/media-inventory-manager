
#ifndef MEDIA_INVENTORY_MANAGER_TRANSACTIONTEST_H
#define MEDIA_INVENTORY_MANAGER_TRANSACTIONTEST_H

#include <iostream>
#include <iomanip>
//#include <utility>
#include "../src/transaction.h"
#include "formatted_test_output_funcs.h"


using namespace std;

namespace transaction_test {

/**
 *
 * @param be_verbose a bool that we can use to toggle output describing each
 *                   individual test case being conducted
 * @return a boolean value stating if the test failed or if it threw an error
 */
  bool test_transaction_constructor_implementation(const bool &be_verbose) {
    
    bool all_tests_passed = true;
    
    if (be_verbose) {
      cout << "[+] test Transaction construction for class Transaction" << endl;
    }
    try {
      Transaction one_day_rent_len(1);
      
      one_day_rent_len = Transaction(2);
//    double time1, time2;
      {
        Transaction default_empty_const;
        /*time1 = */default_empty_const.unixTimeCheckedOut();
      }
      
      {
        Transaction default_empty_const = Transaction();
        /*time2 = */default_empty_const.unixTimeCheckedOut();
      }
      
    } catch (std::exception &e) {
      all_tests_passed = false;
    }
    try {
      Transaction t(0);
      
    } catch (std::exception &e) {
      all_tests_passed = false; // if we get passed Transaction
    }
    
    return all_tests_passed;
  };
  
  bool test_transaction_isDue_function_implementation(const bool &be_verbose,Transaction &t) {
    if (be_verbose) {
      cout << "[+] test Transaction::isDue() function for class Transaction"
           << endl;
    }
    try {
      t.isDue();
    } catch (std::exception &e) {
      return false;
    }
    return true;
  }
  
  bool test_unixTimeCheckedOut_implementation(const bool &be_verbose,Transaction &t) {
      if (be_verbose) {
        cout << "[+] test Transaction::unixTimeCheckedOut() function for class Transaction"
             << endl;
      }
      try {
        t.unixTimeCheckedOut();
      } catch (std::exception &e) {
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
  bool test_transaction(const bool &be_verbose) {
    
    bool all_passed = true;
    
    // alias to just x in order to keep code more readable.
    int x = testNameLen;
    
    
    std::string funcName = "test_transaction_constructor_implementation";
    // testing the Transaction constructor as an independent object.
    cout << left << setw(pf) << "[+] performing test" << left << ":"
         << setw(x) << right << funcName
         << endl;
    if (test_transaction_constructor_implementation(be_verbose)) {
      test_passed_output(funcName);
      
      // if the ctor test has succeeded, we are safe to proceed with all other
      // function tests for Transaction.
      
      Transaction t_3day = Transaction();
      Transaction t_0day = Transaction(0);
      Transaction t_1day = Transaction(1);
      
      funcName = "test_transaction_isDue_function_implementation";
      // testing the Transaction constructor as an independent object.
      cout << left << setw(pf) << "[+] performing test" << left << ":"
           << setw(x) << right << funcName
           << endl;
      if (test_transaction_isDue_function_implementation(be_verbose, t_3day)) {
        test_passed_output(funcName);
      } else {
        test_failed_outptut(funcName);
        all_passed = false;
      }
  
      funcName = "test_unixTimeCheckedOut_implementation";
      // testing the Transaction constructor as an independent object.
      cout << left << setw(pf) << "[+] performing test" << left << ":"
           << setw(x) << right << funcName
           << endl;
      if (test_unixTimeCheckedOut_implementation(be_verbose, t_3day)) {
        test_passed_output(funcName);
      } else {
        test_failed_outptut(funcName);
        all_passed = false;
      }
      
    } else {
      test_failed_outptut(funcName);
      all_passed = false;
    }
    return all_passed;
  }
  
}

#endif //MEDIA_INVENTORY_MANAGER_TRANSACTIONTEST_H

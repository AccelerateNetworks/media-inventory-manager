#include <iostream>
#include <iomanip>
#include "movietest.h"
#include "hashtabletest.h"

using namespace std;

void test_passed_output(const string &testName, int testNameLen){
  int myLen = /*9 + */testNameLen;
  cout << left << setw(20) << "[+] passed" << left << ":" << setw(myLen)
       << right
       << testName << endl;
}

void test_failed_outptut(const string &testName, int testNameLen){
  int myLen = /*9 + */testNameLen;
  cout << left << setw(20)  << "[-] failed" << left << ":" << setw(myLen) <<
       right
       << testName << endl;
}

/**
 *      * the first try/catch block handles testing the movie constructor
 *      against the different parameter needs for each of our movie genres.
 *
 *      *
 *
 * @param be_verbose
 */
void movie_testing(const bool& be_verbose){
  
  int x = 44;// 42 is the longest test method name I made for this test set
  int myLen = 20;
  
  //  testing the movie constructor against the different parameter needs for each of our movie genres.
  try {
    cout << left << setw(20) << "[+] performing test" << left << ":" <<
         setw(myLen)
         << right << "test_each_genre_constructor_implementation"
         << endl;
    if(test_each_genre_constructor_implementation(be_verbose)){
      test_passed_output( "test_each_genre_constructor_implementation",x);
    }else {
      test_failed_outptut("test_each_genre_constructor_implementation",x);
    }
    
  }catch (std::exception e){

    // if we have a failure, we need to identify where... so lets break the
    // test out into a per genre basis
    
    // testing classic parameters in ctor
    cout << left << setw(20) << "[+] performing test" << left << ":"
         << setw(myLen) << right << "test_classic_constructor_implementations"
         << endl;
    if(test_each_genre_constructor_implementation(be_verbose)) {
      test_passed_output("test_classic_constructor_implementations", x);
    }else {
      test_failed_outptut("test_classic_constructor_implementations", x);
    }
    
    // testing drama parameters in ctor
    cout << left << setw(20) << "[+] performing test" << left << ":"
         << setw(myLen) << right << "test_drama_constructor_implementations"
         << endl;
    if(test_each_genre_constructor_implementation(be_verbose)) {
      test_passed_output("test_drama_constructor_implementations", x);
    }else {
      test_failed_outptut("test_drama_constructor_implementations", x);
    }
    
    // testing comedy parameters in ctor
    cout << left << setw(20) << "[+] performing test" << left << ":"
         << setw(myLen) << right << "test_comedy_constructor_implementations"
         << endl;
    if(test_each_genre_constructor_implementation(be_verbose)) {
      test_passed_output("test_comedy_constructor_implementations", x);
    }else {
      test_failed_outptut("test_comedy_constructor_implementations", x);
    }
  }
  
  
}

int main() {
	cout << "[+] Running all tests -" << endl;
  hashTableTest();
  
  
  
  cout << "\t\t class Movie testing START" << endl;
  // the bool parameter is used to toggle verbose  mode of test functions
  movie_testing(false); // try/catch block is inside this function
  cout << "\t\t class Movie testing END" << endl;
  
  
  

  return 0;
}

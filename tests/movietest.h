
#ifndef MEDIA_INVENTORY_MANAGER_MOVIETEST_H
#define MEDIA_INVENTORY_MANAGER_MOVIETEST_H

#include <iostream>
#include <utility>
#include "../src/movie.h"


using namespace std;

/**
 *
 * @param testName
 * @param testNameLen
 */
void test_passed_output(const string &testName, int testNameLen){
  int myLen = testNameLen;
  cout << left << setw(20) << "[+] passed" << left << ":" << setw(myLen)
       << right
       << testName << endl;
}

/**
 *
 * @param testName
 * @param testNameLen
 */
void test_failed_outptut(const string &testName, int testNameLen){
  int myLen = testNameLen;
  cout << left << setw(20)  << "[-] failed" << left << ":" << setw(myLen) <<
       right
       << testName << endl;
}

/**
 *
 * @param verbose
 * @return
 */
bool test_each_genre_constructor_implementation(const bool &verbose){

/*
 * C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942
 * C, 10, Michael Curtiz, Casablanca, Humphrey Bogart 8 1942
 *
 * D, 10, Barry Levinson, Good Morning Vietnam, 1988
 * D, 10, Gus Van Sant, Good Will Hunting, 2000
 *
 * F, 10, Gore Verbinski, Pirates of the Caribbean, 2003
 * F, 10, Joel Coen, Fargo, 1996
 *
 *
 * Movie(string title, string year, string director, string genre);
 *
* */
/*
  The items should be sorted as follows:
  
  comedy   (‘F’) by: Title, then Year it released
  dramas   (‘D’) by: Director, then Title
  classics (‘C’) by: Release date, then Major actor
*/
  if(verbose) {
    cout << "[+] test classic1 construction: Casablanca classic movie entry "
        "for Classic class" << endl;
  }
  
  Movie classic1( "Casablanca",
                    "194208", // usage is yyyymm
                    "Michael Curtiz",
                    "C",
                    "Ingrid Bergman");
  
  if(verbose) {
    cout << "[+] test classic2 construction: Casablanca alter version classic movie"
            " entry for Classic class" << endl;
  }
  
  Movie classic2( "Casablanca",
                    "194208",
                    "Michael Curtiz",
                    "C",
                    "Humphrey Bogart");
  
  
  if(verbose) {
    cout << "[+] test drama1 construction: Good Morning Vietnam Drama movie entry "
        "for Drama class" << endl;
  }
  
  Movie drama1("Good Morning Vietnam",
               "1988",
               "Barry Levinson", "D");
  
  if(verbose) {
    cout << "[+] test drama2 construction: Good Will Hunting drama movie"
        " entry for Drama class" << endl;
  }
  
  Movie drama2( "Good Will Hunting",
                "2000",
                "Gus Van Sant", "D");
  
  if(verbose) {
    cout << "[+] test comedy1 construction: Pirates of the Caribbean comedy movie"
        " entry for Comedy class" << endl;
  }
  
  Movie comedy1( "Pirates of the Caribbean",
                 "2003",
                 "Gore Verbinski", "F");
  if(verbose) {
    cout << "[+] test comedy2 construction: Fargo comedy movie"
        " entry for Comedy class" << endl;
  }
  
  Movie comedy2( "Fargo",
                 "1996",
                 "Joel Coen", "F");
  return true;
};

/**
 *
 * @param verbose
 * @return
 */
bool test_classic_constructor_implementations(const bool &verbose){
  if(verbose) {
    cout << "[+] test classic1 construction: Casablanca classic movie entry "
        "for Classic class" << endl;
  }
  
  Movie classic1( "Casablanca",
                  "194208", // usage is yyyymm
                  "Michael Curtiz",
                  "C",
                  "Ingrid Bergman");
  
  if(verbose) {
    cout << "[+] test classic2 construction: Casablanca alter version classic movie"
        " entry for Classic class" << endl;
  }
  
  Movie classic2( "Casablanca",
                  "194208",
                  "Michael Curtiz",
                  "C",
                  "Humphrey Bogart");
  return true;
  
}

/**
 *
 * @param verbose
 * @return
 */
bool test_drama_constructor_implementations(const bool &verbose){
  
  if(verbose) {
    cout << "[+] test drama1 construction: Good Morning Vietnam Drama movie entry "
        "for Drama class" << endl;
  }
  
  Movie drama1("Good Morning Vietnam",
               "1988",
               "Barry Levinson", "D");
  
  if(verbose) {
    cout << "[+] test drama2 construction: Good Will Hunting drama movie"
        " entry for Drama class" << endl;
  }
  
  Movie drama2( "Good Will Hunting",
                "2000",
                "Gus Van Sant", "D");
  return true;
}

/**
 *
 * @param verbose
 * @return
 */
bool test_comedy_constructor_implementations(const bool &verbose){
  
  if(verbose) {
    cout << "[+] test comedy1 construction: Pirates of the Caribbean comedy movie"
        " entry for Comedy class" << endl;
  }
  
  Movie comedy1( "Pirates of the Caribbean",
                 "2003",
                 "Gore Verbinski", "F");
  if(verbose) {
    cout << "[+] test comedy2 construction: Fargo comedy movie"
        " entry for Comedy class" << endl;
  }
  
  Movie comedy2( "Fargo",
                 "1996",
                 "Joel Coen", "F");
  return true;
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
    cout << left << setw(20) << "[+] performing test" << left << ":"
         << setw(x) << right << "test_each_genre_constructor_implementation"
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
         << setw(x) << right << "test_classic_constructor_implementations" << endl;
    if(test_each_genre_constructor_implementation(be_verbose)) {
      test_passed_output("test_classic_constructor_implementations", x);
    }else {
      test_failed_outptut("test_classic_constructor_implementations", x);
    }
    
    // testing drama parameters in ctor
    cout << left << setw(20) << "[+] performing test" << left << ":"
         << setw(x) << right << "test_drama_constructor_implementations" << endl;
    if(test_each_genre_constructor_implementation(be_verbose)) {
      test_passed_output("test_drama_constructor_implementations", x);
    }else {
      test_failed_outptut("test_drama_constructor_implementations", x);
    }
    
    // testing comedy parameters in ctor
    cout << left << setw(20) << "[+] performing test" << left << ":"
         << setw(x) << right << "test_comedy_constructor_implementations" << endl;
    if(test_each_genre_constructor_implementation(be_verbose)) {
      test_passed_output("test_comedy_constructor_implementations", x);
    }else {
      test_failed_outptut("test_comedy_constructor_implementations", x);
    }
  }
}

#endif //MEDIA_INVENTORY_MANAGER_MOVIETEST_H

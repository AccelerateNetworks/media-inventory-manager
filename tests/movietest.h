
#ifndef MEDIA_INVENTORY_MANAGER_MOVIETEST_H
#define MEDIA_INVENTORY_MANAGER_MOVIETEST_H

#include <iostream>
#include <utility>
#include "../src/movie.h"
#include "formatted_test_output_funcs.h"


using namespace std;

namespace movie_test {



/**
 *
 * @param be_verbose
 * @return
 */
  bool test_classic_constructor(const bool &be_verbose) {
    if (be_verbose) {
      cout << "[+] test classic1 construction: Casablanca classic movie entry "
          "for Classic class" << endl;
    }
    
    Movie classic1("Casablanca",
                   "194208", // usage is yyyymm
                   "Michael Curtiz",
                   "C",
                   "Ingrid Bergman");
    
    if (be_verbose) {
      cout
          << "[+] test classic2 construction: Casablanca alter version classic movie"
              " entry for Classic class" << endl;
    }
    
    Movie classic2("Casablanca",
                   "194208",
                   "Michael Curtiz",
                   "C",
                   "Humphrey Bogart");
    return true;
    
  }

/**
 *
 * @param be_verbose
 * @return
 */
  bool test_drama_constructor(const bool &be_verbose) {
    
    if (be_verbose) {
      cout
          << "[+] test drama1 construction: Good Morning Vietnam Drama movie entry "
              "for Drama class" << endl;
    }
    
    Movie drama1("Good Morning Vietnam",
                 "1988",
                 "Barry Levinson", "D");
    
    if (be_verbose) {
      cout << "[+] test drama2 construction: Good Will Hunting drama movie"
          " entry for Drama class" << endl;
    }
    
    Movie drama2("Good Will Hunting",
                 "2000",
                 "Gus Van Sant", "D");
    return true;
  }

/**
 *
 * @param be_verbose
 * @return
 */
  bool test_comedy_constructor(const bool &be_verbose) {
    
    if (be_verbose) {
      cout
          << "[+] test comedy1 construction: Pirates of the Caribbean comedy movie"
              " entry for Comedy class" << endl;
    }
    
    Movie comedy1("Pirates of the Caribbean",
                  "2003",
                  "Gore Verbinski", "F");
    if (be_verbose) {
      cout << "[+] test comedy2 construction: Fargo comedy movie"
          " entry for Comedy class" << endl;
    }
    
    Movie comedy2("Fargo",
                  "1996",
                  "Joel Coen", "F");
    return true;
  }
  
  /**
 *
 * @param be_verbose
 * @return
 */
  bool test_each_genre_constructor(const bool &be_verbose) {

/*
 * C, 10, Michael Curtiz, Casablanca, Ingrid Bergman 8 1942
 * C, 10, Michael Curtiz, Casablanca, Humphrey Bogart 8 1942
 *
 * D, 10, Barry Levinson, Good Morning Vietnam, 1988
 * D, 10, Gus Van Sant, Good Will Hunting, pf00
 *
 * F, 10, Gore Verbinski, Pirates of the Caribbean, pf03
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
    try {
      if (be_verbose) {
        cout << "[+] test classic1 construction: Casablanca classic movie entry "
            "for Classic class" << endl;
      }
      Movie classic1("Casablanca", "194208", "Michael Curtiz","C","Ingrid Bergman");
    } catch(std::exception& e){
      test_classic_constructor(be_verbose);
    }
  
  
    try{
      if (be_verbose) {
        cout
            << "[+] test classic2 construction: Casablanca alter version classic movie"
                " entry for Classic class" << endl;
      }
      Movie classic2("Casablanca","194208","Michael Curtiz","C","Humphrey Bogart");
    }catch(std::exception& e){
      test_classic_constructor(be_verbose);
    }
  
    try{
      if (be_verbose) {
        cout
            << "[+] test drama1 construction: Good Morning Vietnam Drama movie entry "
                "for Drama class" << endl;
      }
      Movie drama1("Good Morning Vietnam","1988","Barry Levinson", "D");
    }catch(std::exception& e){
      test_drama_constructor(be_verbose);
    }
  
    try{
      if (be_verbose) {
        cout << "[+] test drama2 construction: Good Will Hunting drama movie"
            " entry for Drama class" << endl;
      }
      Movie drama2("Good Will Hunting","2000","Gus Van Sant", "D");
    }catch(std::exception& e){
      test_drama_constructor(be_verbose);
    }
  
    try{
      if (be_verbose) {
        cout
            << "[+] test comedy1 construction: Pirates of the Caribbean comedy movie"
                " entry for Comedy class" << endl;
      }
      Movie comedy1("Pirates of the Caribbean","2003","Gore Verbinski", "F");
    }catch(std::exception& e){
      test_comedy_constructor(be_verbose);
    }
  
    try{
      if (be_verbose) {
        cout << "[+] test comedy2 construction: Fargo comedy movie"
            " entry for Comedy class" << endl;
      }
      Movie comedy2("Fargo","1996","Joel Coen", "F");
    }catch(std::exception& e){
      test_comedy_constructor(be_verbose);
    }
    return true;
  };
  
/**
 *      * the first try/catch block handles testing the movie constructor
 *      against the different parameter needs for each of our movie genres.
 *
 *      *
 *
 * @param be_verbose
 */
  void movie_testing(const bool &be_verbose) {
    
    int l = testNameLen;
    
    //  testing the movie constructor against the different parameter needs for each of our movie genres.
    try {
      cout << left << setw(pf) << "[+] performing test" << left << ":"
           << setw(l) << right << "test_each_genre_constructor"
           << endl;
      if (test_each_genre_constructor(be_verbose)) {
        test_passed_output("test_each_genre_constructor");
      } else {
        test_failed_outptut("test_each_genre_constructor");
      }
      
    } catch (std::exception e) {
      
      // if we have a failure, we need to identify where... so lets break the
      // test out into a per genre basis
      
      // testing classic parameters in ctor
      cout << left << setw(pf) << "[+] performing test" << left << ":"
           << setw(l) << right << "test_classic_constructor"
           << endl;
      if (test_each_genre_constructor(be_verbose)) {
        test_passed_output("test_classic_constructor");
      } else {
        test_failed_outptut("test_classic_constructor");
      }
      
      // testing drama parameters in ctor
      cout << left << setw(pf) << "[+] performing test" << left << ":"
           << setw(l) << right << "test_drama_constructor"
           << endl;
      if (test_each_genre_constructor(be_verbose)) {
        test_passed_output("test_drama_constructor");
      } else {
        test_failed_outptut("test_drama_constructor");
      }
      
      // testing comedy parameters in ctor
      cout << left << setw(pf) << "[+] performing test" << left << ":"
           << setw(l) << right << "test_comedy_constructor"
           << endl;
      if (test_each_genre_constructor(be_verbose)) {
        test_passed_output("test_comedy_constructor");
      } else {
        test_failed_outptut("test_comedy_constructor");
      }
    }
  }
}
#endif //MEDIA_INVENTORY_MANAGER_MOVIETEST_H

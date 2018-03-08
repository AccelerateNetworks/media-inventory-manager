//
// Created by Peter on 3/7/2018.
//

#ifndef MEDIA_INVENTORY_MANAGER_MOVIETEST_H
#define MEDIA_INVENTORY_MANAGER_MOVIETEST_H

#include <iostream>
#include "../src/movie.h"


using namespace std;


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

#endif //MEDIA_INVENTORY_MANAGER_MOVIETEST_H

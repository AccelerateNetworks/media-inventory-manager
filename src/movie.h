#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <utility>

using std::string;
using std::vector;
using std::ostream;

#include "media.h"



enum class MovieType : char { COMEDY = 'F', DRAMA = 'D', CLASSIC = 'C'};

class Movie : public Media {
  
  string director;
  string genre;
  vector<string> actors;
  
  
  // for safety, I'm adding a functino for clearing the existing contents of a
  // Movie object to make it safe for the assignment operator.
  
  void clear();
  
 public:
  
  Movie();
  
  /**
   *
   * @param title
   * @param year
   * @param director
   * @param genre
   */
  Movie(string title, string year, string director, string genre);
  
  /**
   *
   * @param title
   * @param year
   * @param director
   * @param genre
   * @param actor
   */
  Movie(string title, string year, string director, string genre, string actor);
  
  /**
   *
   * @param other
   */
  Movie(const Movie& other);
  
  /**
   *
   */
  void addActor(string);
  
  /**
   *
   * @return
   */
  string getDirector() const;
  
  /**
   *
   * @return
   */
  string getGenre() const;
  
  /**
   *
   * @return
   */
  vector<string> getAllActors() const;
  
  /**
   *
   * @return
   */
  bool hasActor(string) const;
  
  /**
   *
   * @param os
   */
  void feedToOutstream(std::ostream &os) const override;
  

  
  // implementing assignment operator overload:
  
  Movie&operator=(const Movie& rhs);
  
  // equality operator overloads:
  
  /**
   *
   * @param rhs
   * @return
   */
  bool operator==(const Movie& rhs) const;
  
  /**
   *
   * @param other
   * @return
   */
  bool operator!=(const Movie& other) const;
  
  // relational operator overaloads:
  
  /**
   *
   * @param rhs
   * @return
   */
  bool operator<(const Movie &rhs) const;
  
  /**
   *
   * @param rhs
   * @return
   */
  bool operator>(const Movie &rhs) const;
  
  /**
   *
   * @param rhs
   * @return
   */
  bool operator<=(const Movie &rhs) const;
  
  /**
   *
   * @param rhs
   * @return
   */
  bool operator>=(const Movie &rhs) const;
  
  /**
   *
   * @return
   */
  int hash() override;
  
  /**
   *
   * @return
   */
  ostream& operator<<(ostream&);
  
  /**
   *
   */
   struct Comparable{
     char gnr;
     string prim;
     string sec;
     Comparable():gnr(' '),prim(""), sec(""){};
     Comparable(const char& gnr, const string& pr, const string& sc) // NOLINT
         :gnr(gnr), prim(pr), sec(sc){}
     
     ~Comparable() = default;
   }comp;

  
};

#endif //MOVIE_H

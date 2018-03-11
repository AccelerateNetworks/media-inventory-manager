#ifndef MOVIE_H
#define MOVIE_H

#include "media.h"

#include <iostream>
#include <string>
#include <utility>
#include <vector>
#include <utility>

using std::string;
using std::vector;
using std::ostream;

enum class MovieType : char { COMEDY = 'F', DRAMA = 'D', CLASSIC = 'C'};

class Movie : public Media {
  
  string director;
  string genre;
  vector<string> actors;

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
  int hash();
  
  /**
   *
   * @return
   */
  ostream& operator<<(ostream&);
  
  /**
   *
   */
  union compare_movies{
    char c{}; // the low cost means for intializing the union
    
    std::pair<string, string> comedy;
    std::pair<string,string> drama;
    std::pair<string, string> classic;
    
    ~compare_movies(){};
    
    compare_movies():c(' '){}
  }comparable;

  
};

#endif //MOVIE_H

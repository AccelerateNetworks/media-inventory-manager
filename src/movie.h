#ifndef MOVIE_H
#define MOVIE_H

#include "media.h"

#include <iostream>
#include <string>
#include <vector>
#include <utility>

using std::string;
using std::vector;
using std::ostream;



class Movie : public Media {

  string director;
  string genre;
  vector<string> actors;

 public:

  Movie(string title, string year, string director, string genre);
  Movie(string title, string year, string director, string genre, string actor);
  
  void addActor(string);
  string getDirector();
  string getGenre();
  vector<string> getAllActors();
  bool hasActor(string);

  string hash();
  ostream& operator<<(ostream&);
  
};

#endif //MOVIE_H

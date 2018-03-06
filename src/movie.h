#ifndef MOVIE_H
#define MOVIE_H

#include "media.h"

#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::ostream;

public enum class MovieType {COMEDY, CLASSIC, DRAMA};

class Movie : public Media {

  MovieType EnumGenre;
  string director;
  string genre;
  vector<string> actors;

 public:

 Movie(string, string, string, string) : Media(string, string, MediaType);
  void addActor(string);
  string getDirector();
  string getGenre();
  vector<string> getActors();
  bool hasActor(string);

  string operator#();
  ostream& operator<<(ostream&);
};

#endif //MOVIE_H

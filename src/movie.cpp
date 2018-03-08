#include "movie.h"
#include <utility>

/**
 *
 * @param title
 * @param year
 * @param director
 * @param genre
 */
Movie::Movie(string title, string year, string director, string genre)
  : Media(MediaType::MOVIE, std::move(title), std::move(year)),
    director(std::move(director)),
    genre(std::move(genre)) {
 }

 /**
  *
  * @param title
  * @param year
  * @param director
  * @param genre
  * @param actor
  */
Movie::Movie(string title, string year, string director, string genre,
             string actor)
    :Media(MediaType::MOVIE, std::move(title), std::move(year)),
     director(std::move(director)),
     genre(std::move(genre))  {
  actors.push_back(actor);
}

/**
 *
 * @param boyo
 */
void Movie::addActor(string boyo){
  this->actors.push_back(boyo);
}

/**
 *
 * @return
 */
string Movie::getDirector(){
  return this->director;
}

/**
 *
 * @return
 */
string Movie::getGenre(){
  return this->genre;
}

/**
 *
 * @return
 */
vector<string> Movie::getAllActors(){
  return this->actors;
}

/**
 *
 * @param boyoMcBoyeeee
 * @return
 */
bool Movie::hasActor(string boyoMcBoyeeee){
  for(string s : this->actors){
    if(s == boyoMcBoyeeee){
      return true;
    }
  }

  return false;
}

/**
 *
 * @return
 */
string Movie::hash(){
  string hash = ""+this->genre[0];
  // TODO: work out better, non dummy output
  return hash;
}

/**
 *
 * @param output
 * @return
 */
ostream& Movie::operator<<(ostream& output){
  output << "Movie: " << this->getTitle() << ", " << this->getYear();
  return output;
}


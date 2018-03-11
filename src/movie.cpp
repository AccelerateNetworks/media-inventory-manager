#include "movie.h"
#include <utility>

enum class MediaType;

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
string Movie::getDirector() const {
  return this->director;
}

/**
 *
 * @return
 */
string Movie::getGenre() const {
  return this->genre;
}

/**
 *
 * @return
 */
vector<string> Movie::getAllActors() const {
  return this->actors;
}

/**
 *
 * @param boyoMcBoyeeee
 * @return
 */
bool Movie::hasActor(string boyoMcBoyeeee) const {
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
int Movie::hash(){
  return (int) this->getTitle()[0];
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

void Movie::feedToOutstream(std::ostream &os) const {
  os << this->getGenre() << ", " << this->getDirector() << ", "
     << this->getTitle() << ", ";
  
  if(genre == "F" || genre == "D"){
    os << this->getYear();
  }else if( genre == "C"){
    
    for(const auto& itm : actors)os << itm << ", ";
    
    string s;
    if(getYear().length() > 4){
      s = getYear().substr(4,2) + getYear().substr(0,4);
    }else {
      s = getYear();
    }
    os << s;
  }
}


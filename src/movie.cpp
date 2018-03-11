#include "movie.h"
#include <utility>
#include <string>

enum class MediaType;

Movie::Movie()
    :Media(MediaType::MOVIE, "", "201800"),
     director(""),
     genre("")
{}

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
    genre(std::move(genre)){

  if(genre == "F"){
    comparable.comedy.first = title, comparable.comedy.second = year;
  } else if(genre == "D"){
    comparable.drama.first = director, comparable.drama.second = title;
  }
  
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
  
  if(genre == "F"){
    comparable.comedy.first = title, comparable.comedy.second = year;
  } else if(genre == "D"){
    comparable.drama.first = director, comparable.drama.second = title;
  } else if(genre == "C"){
    comparable.classic.first = year, comparable.classic.second = actor;
  }
  
}

/**
 *
 * @param other
 */
Movie::Movie(const Movie &other)
    :Media(MediaType::MOVIE, (other.getTitle()),(other.getYear())),
     director(other.getDirector()),
     genre(other.getGenre()){
  if(genre == "C")actors = other.getAllActors();
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

/**
 *
 * @param os
 */
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

/**
 * Bahahaha! Look at this block of bullshit I've made!!! lol
 * @param rhs the object we are comparing *this against
 * @return true in the following conditions, otherwise false:
 *              if genre == rhs.genre
 *              {
 *                if primary criteria == rhs.primary criteria
 *                {
 *                    return if secondary criteria == rhs.secondary criteria
 *                }
 *              }
 *              return false;
 */
bool Movie::operator==(const Movie &rhs) const {
  if(genre == rhs.getGenre()){
    switch (genre.at(0)){
      
      case static_cast<const char>(MovieType::COMEDY):
        if(comparable.comedy.first == rhs.comparable.comedy.first){
          return comparable.comedy.second == rhs.comparable.comedy.second;
        }
        break;
        
      case static_cast<const char>(MovieType::DRAMA):
        if(comparable.drama.first == rhs.comparable.drama.first){
          return comparable.drama.second == rhs.comparable.drama.second;
        }
        break;
        
      case static_cast<const char>(MovieType::CLASSIC):
        if(comparable.classic.first == rhs.comparable.classic.first){
          return comparable.classic.second == rhs.comparable.classic.second;
        }
        break;
        
      default:break;
    }
  }
  return false;
}

/**
 *
 * @param other
 * @return
 */
bool Movie::operator!=(const Movie &other) const {
  return !(*this == other);
}

/**
 * Bahahaha! Look at this block of bullshit I've made!!! lol
 * @param rhs the object we are comparing *this against
 * @return true in the following conditions, otherwise false:
 *              if genre < rhs.genre : return true;
 *              else if genre == rhs.genre
 *              {
 *                  if primary criteria < rhs.primary criteria : return true;
 *                  else if primary criteria == rhs.primary criteria
 *                  {
 *                      if secondary criteria < rhs.secondary criteria : return true;
 *                  }
 *              }
 *              return false;
 */
bool Movie::operator<(const Movie &rhs) const {
  if(genre == rhs.getGenre()){
    switch (genre.at(0)){
      
      case static_cast<const char>(MovieType::COMEDY):
        if(comparable.comedy.first == rhs.comparable.comedy.first){
          return comparable.comedy.second < rhs.comparable.comedy.second;
        } else return comparable.comedy.first < rhs.comparable.comedy.first;
        
      case static_cast<const char>(MovieType::DRAMA):
        if(comparable.drama.first == rhs.comparable.drama.first){
          return comparable.drama.second < rhs.comparable.drama.second;
        } else return comparable.drama.first < rhs.comparable.drama.first;
        
      case static_cast<const char>(MovieType::CLASSIC):
        if(comparable.classic.first == rhs.comparable.classic.first){
          return comparable.classic.second < rhs.comparable.classic.second;
        } else return comparable.classic.first < rhs.comparable.classic.first;
        
      default:return false;
    }
  } else return genre < rhs.getGenre();
  
}

/**
 *
 * @param rhs
 * @return
 */
bool Movie::operator>(const Movie &rhs) const {
  return rhs < *this;
}

/**
 *
 * @param rhs
 * @return
 */
bool Movie::operator<=(const Movie &rhs) const {
  return !(rhs < *this);
}

/**
 *
 * @param rhs
 * @return
 */
bool Movie::operator>=(const Movie &rhs) const {
  return !(*this < rhs);
}



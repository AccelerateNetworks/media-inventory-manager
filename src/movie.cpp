#include "movie.h"
#include <utility>
#include <string>

enum class MediaType;

int Movie::NEXT_ID = 0;

Movie::Movie()
    :Media(MediaType::MOVIE, "", "201800"),
     director(""),
     genre(""),
     id(GETNEXTID())
{}

int Movie::GETNEXTID(){
  return NEXT_ID++;
}

int Movie::getId(){
  return this->id;
}

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
    genre(std::move(genre)),
    id(GETNEXTID()){
  comp.gnr = static_cast<char>((genre.length() > 0)? genre.at(0): ' ');
  switch (comp.gnr){
    case static_cast<char>(MovieType::COMEDY):
      comp.prim = title;
      comp.sec = year;
      break;
    case static_cast<char>(MovieType::DRAMA):
      comp.prim = director;
      comp.sec = title;
      break;
    default:break;
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
     genre(std::move(genre)),
     id(GETNEXTID()) {
   
  actors.push_back(actor);
  
   comp.gnr = static_cast<char>((genre.length() > 0)? genre.at(0): ' ');
   
   switch (comp.gnr){
     case static_cast<char>(MovieType::COMEDY):
       comp.prim = title;
       comp.sec = year;
       break;
     case static_cast<char>(MovieType::DRAMA):
       comp.prim = director;
       comp.sec = title;
       break;
     case static_cast<char>(MovieType::CLASSIC):
       comp.prim = year;
       comp.sec = actor;
       break;
     default:break;
   }
  
}

/**
 *
 * @param other
 */
Movie::Movie(const Movie &other)
    :Media(MediaType::MOVIE, (other.getTitle()),(other.getYear())),
     director(other.getDirector()),
     genre(other.getGenre()),
     id(GETNEXTID()){
  
  comp.gnr = static_cast<char>((genre.length() > 0)? genre.at(0): ' ');
  
  switch (comp.gnr){
    case static_cast<char>(MovieType::COMEDY):
      comp.prim = other.getTitle();
      comp.sec = other.getYear();
      break;
    case static_cast<char>(MovieType::DRAMA):
      comp.prim = director;
      comp.sec = other.getTitle();
      break;
    case static_cast<char>(MovieType::CLASSIC):
      comp.prim = other.getYear();
      comp.sec = other.getAllActors()[0];
      actors = other.getAllActors();
      break;
    default:break;
  }
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
  for(const string& s : this->actors){
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
    os << (getYear().length() > 4
          ? getYear().substr(4, 2) + getYear().substr(0, 4)
          : getYear());
  }
}

/** strips the existing movie of all references to past values for type-safe
 *  assignment operation.
 *
 */
void Movie::clear() {
  // Including all of the self-cleaning state members in this list as well,
  // but will keep them comented out. This is just for convenience should
  // member types change down the road.
  
  genre = string();
  director = string();
  this->actors.clear();
  comp.gnr = ' ';
  comp.prim = string();
  comp.sec = string();
  
}

/**
 *
 * @param rhs
 * @return
 */
Movie &Movie::operator=(const Movie &rhs) {
  if(this == &rhs || *this == rhs)return *this;
  this->clear();
  setType(rhs.getType());
  setTitle(rhs.getTitle());
  setYear(rhs.getYear());
  director = rhs.getDirector();
  genre = rhs.getGenre();
  actors = vector<string>(rhs.actors);
  comp = Comparable(rhs.comp.gnr, rhs.comp.prim, rhs.comp.sec );
  id = rhs.getId():
  return *this;
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
  return this->id == rhs.getId();
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
  if(comp.gnr == rhs.comp.gnr){
    if(comp.prim == rhs.comp.prim)return comp.sec < rhs.comp.sec;
    else return comp.prim < rhs.comp.prim;
  }
  else return comp.gnr < rhs.comp.gnr;
  
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





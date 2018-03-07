#include "movie.h"
#include <utility>

Movie::Movie(string title, string year, string director, string genre)
  : Media(MediaType::MOVIE, std::move(title), std::move(year)), director(std::move(director)), genre(
    std::move(genre)) {
 }

void Movie::addActor(string boyo){
  this->actors.push_back(boyo);
}

string Movie::getDirector(){
  return this->director;
}

string Movie::getGenre(){
  return this->genre;
}

vector<string> Movie::getAllActors(){
  return this->actors;
}

bool Movie::hasActor(string boyoMcBoyeeee){
  for(string s : this->actors){
    if(s == boyoMcBoyeeee){
      return true;
    }
  }

  return false;
}

string Movie::hash(){
  string hash = ""+this->genre[0];
  // TODO: work out better, non dummy output
  return hash;
}

ostream& Movie::operator<<(ostream& output){
  output << "Movie: " << this->getTitle() << ", " << this->getYear();
  return output;
}

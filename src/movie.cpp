#include "movie.h"

Movie::Movie(string title, string year, string director, string genre)
  : Media(MediaType::MOVIE, title, year), director(director), genre(genre) {

  if(genre == "drama") this->EnumGenre = MovieType::DRAMA;
  if(genre == "comedy") this->EnumGenre = MovieType::COMEDY;
  if(genre == "classic") this->EnumGenre = MovieType::CLASSIC;
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

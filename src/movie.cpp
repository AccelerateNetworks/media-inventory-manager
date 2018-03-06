#include "movie.h"

Movie::Movie(string title, string year, string director, string genre)
  : Media(MediaType::MOVIE, title, year), director(director), genre(genre) {

  switch (genre){
  case "comedy": this->EnumGenre = MovieType::COMEDY; break;
  case "classic": this->EnumGenre = MovieType::CLASSIC; break;
  case "drama": this->EnumGenre = MovieType::DRAMA; break;
  }
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

bool hasActor(string boyoMcBoyeeee){
  for(string s : this->actors){
    if(s == boyoMcBoyeeee){
      return true;
    }
  }

  return false;
}

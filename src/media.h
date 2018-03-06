#ifndef MEDIA_H
#define MEDIA_H

#include <stream>
#include <string>
using std::string;

public enum class MediaType {MOVIE, CD, USB};

class Media {

  MediaType type;
  string title;
  string year;

 public:

  Media(MediaType type, string title, string year){
    title = title;
    year = year;
    type = type;
  }

  virtual string operator#() = 0;
  MediaType getType(){return this->type;}
  string getTitle(){return this->title;}
  string getYear(){return this->year;}

  virtual ostream& operator<<(ostream& out) = 0;
};

#endif //MEDIA_H

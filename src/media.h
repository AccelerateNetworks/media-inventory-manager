#ifndef MEDIA_H
#define MEDIA_H

#include <iostream>
#include <string>
#include <utility>

using std::string;
using std::ostream;

enum class MediaType {MOVIE = 0, CD = 1, USB = 2};

class Media {
public:
  
  Media(MediaType type, string title, string year)
      :type(type), title(std::move(title)), year(std::move(year)){
  }
  
  virtual string hash() = 0;
  MediaType getType(){return this->type;}
  string getTitle(){return this->title;}
  string getYear(){return this->year;}
  
  virtual ostream& operator<<(ostream& out) = 0;
  
private:
  
  MediaType type;
  string title;
  string year;


};

#endif //MEDIA_H

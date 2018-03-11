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
  
  virtual int hash(){
    return (int)title.at(0);
  };
  
  MediaType getType()const {return this->type;};
  string getTitle()const {return this->title;};
  string getYear()const {return this->year;};
  
  
  // we can't create ostream& as being a pure virtual function
  // instead we can create a custom function that takes in an ostream
  // reference, feeds it the desired data, and then returns that object to
  // the operator<< overload we implement in our derived classes.
//  virtual ostream& operator<<(ostream& out);

  // we can now define this function in our derived classes, and then call it
  // from inside the operator<< overload in those derived classes.
  virtual void feedToOutstream(std::ostream& os)const{
    switch((int)type){
      case 0:
        os << "Movie";
        break;
      case 1:
        os << "CD";
        break;
      case 2:
        os << "USB";
        break;
      default: os << "YOU ARE SO $#%&ED";
      break;
    }
    os << ", " << title << ", " << year << std::endl;
  }

protected:
  
  void setType(const MediaType& mt){ type = mt; }
  
  void setTitle(const string& ttl){ title = ttl;}
  
  void setYear(const string& yr){ year = yr;}
  
private:
  
  MediaType type;
  string title;
  string year;


};

#endif //MEDIA_H

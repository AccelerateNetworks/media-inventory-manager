

#ifndef MEDIA_INVENTORY_MANAGER_IMEDIA_GETTERS_SETTERS_H
#define MEDIA_INVENTORY_MANAGER_IMEDIA_GETTERS_SETTERS_H

#include <string>


class IMedia {
public:
  
  enum class MediaType : short { MOVIE = 0, MUSIC = 1, USB = 2 };
  
  virtual std::string getTitle() const = 0;
  
  virtual int getYear() const = 0;
  
  virtual MediaType getMediaType() const = 0;
  
  virtual int compareMedia(const IMedia& rhs) const = 0;
  
};
#endif //MEDIA_INVENTORY_MANAGER_IMEDIA_GETTERS_SETTERS_H

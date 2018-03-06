
#ifndef MEDIA_INVENTORY_MANAGER_DRAMA_H
#define MEDIA_INVENTORY_MANAGER_DRAMA_H

#include "movie.h"

class Drama : public Movie {
public:
  Drama( const std::string &medTitle,
         int year,
         int month,
         std::string dir );
  
  Drama( const std::string &medTitle,
         int year,
         int month,
         std::string dir,
         std::string actor);
  
  virtual ~Drama();
};


#endif //MEDIA_INVENTORY_MANAGER_DRAMA_H
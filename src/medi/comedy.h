
#ifndef MEDIA_INVENTORY_MANAGER_COMEDY_H
#define MEDIA_INVENTORY_MANAGER_COMEDY_H


#include "movie.h"

class Comedy : public Movie{
public:
  
  /**
   *
   * @param medTitle
   * @param year
   * @param month
   * @param dir
   */
  Comedy(
      const std::string &medTitle,
      int year,
      int month,
      std::string dir
  );
  
  /**
   *
   * @param medTitle
   * @param year
   * @param month
   * @param dir
   * @param actor
   */
  Comedy(const std::string &medTitle, int year, int month, std::string dir,
         std::string actor);
  
  virtual ~Comedy();

private:
  // establishing the empty constructor as private
  // in order to prevent people from creating a useless
  // empty, Movie object.
  Comedy();
};


#endif //MEDIA_INVENTORY_MANAGER_COMEDY_H
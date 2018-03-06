

#ifndef MEDIA_INVENTORY_MANAGER_MOVIE_H
#define MEDIA_INVENTORY_MANAGER_MOVIE_H

#include <vector>
#include "icriteria.h"
#include "movie_enums.h"
#include "media.h"



class Movie :  public ICriteria, public Media{

private:
  /**
   *
   */
  MovieType movType;

  /**
   *
   */
  std::string dirctr;

public:

  /**
   *
   */
  Movie();

  /**
   *
   * @param medType
   * @param medTitle
   * @param year
   * @param dir
   * @param actor
   */
  Movie(MediaType mediaType, MovieType movieType, std::string medTitle,
        int year, std::string dir, int releaseMonth,
        std::string majorActor);


  /**
   *
   */
  virtual ~Movie();

  /**
   *
   * @param rhs
   * @return
   */
  virtual int compareMovies(const Movie &rhs) const;

  /**
   *
   * @return
   */
  MovieType getMovieType() const override;
   /**
   *
   * @param rhs
   * @return
   */
  virtual int compareMedia(const IMedia &rhs) const override
  {
    return (getMediaType() < rhs.getMediaType())? (short)-1
          :(getMediaType() > rhs.getMediaType())? (short) 1
          :(short) 0;
  }

};


#endif //MEDIA_INVENTORY_MANAGER_MOVIE_H

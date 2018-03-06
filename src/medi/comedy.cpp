

#include "comedy.h"

/**
 *
 * @param medTitle
 * @param year
 * @param month
 * @param dir
 */
Comedy::Comedy( const std::string &medTitle,
                int year,
                int month,
                std::string dir )
    : Movie(MediaType::MOVIE,
            MovieType::COMEDY,
            medTitle,
            year,
            std::move(dir),
            month,
            "")
{ } // end Classic::Classic(...)

/**
 *
 * @param medTitle
 * @param year
 * @param month
 * @param dir
 * @param actor
 */
Comedy::Comedy( const std::string &medTitle,
                int year,
                int month,
                std::string dir,
                std::string actor)
    : Movie(MediaType::MOVIE,
            MovieType::COMEDY,
            medTitle,
            year,
            std::move(dir),
            month,
            actor)
{ }

Comedy::~Comedy() {

}
// end Classic::Classic(...)
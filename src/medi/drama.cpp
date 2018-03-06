
#include "drama.h"


/**
 *
 * @param medTitle
 * @param year
 * @param month
 * @param dir
 */
Drama::Drama( const std::string &medTitle,
                int year,
                int month,
                std::string dir )
    : Movie(MediaType::MOVIE,
            MovieType::DRAMA,
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
Drama::Drama( const std::string &medTitle,
                int year,
                int month,
                std::string dir,
                std::string actor)
    : Movie(MediaType::MOVIE,
            MovieType::DRAMA,
            medTitle,
            year,
            std::move(dir),
            month,
            actor)
{ }

Drama::~Drama() {

}
// end Classic::Classic(...)
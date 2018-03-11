#include <cassert>
#include "transaction.h"


/**
 * This ctor accepts an integer value for the number of days until the
 * inventory associated with this particular transaction instance is due. The
 * value needs to be 1 or greater.
 *
 * Rather than throwing an error should the input be less than 1 day, the
 * ctor will automatically default the rental duration to 3 days.
 * @param rental_length an integer for the desired number of days until this
 * rental comes due
 */
Transaction::Transaction(int rental_length = 3) {
  if(rental_length < 1) rental_length = 3;
  assert(rental_length > 0);
  unixTimeDue = calc_return_date( rental_length );
}

bool Transaction::isDue() const {
  return system_clock::to_time_t(system_clock::now()) >= unixTimeDue;
}

uint64_t Transaction::unixTimeCheckedOut() const {
  return (uint64_t)unixTimeOfCheckout;
}

bool Transaction::contains(const Movie &arg) const {
  for(const Movie& itm : contents)if(arg.getTitle() == itm.getTitle()) {
      return true;
    }
  return false;
}

std::vector<Movie> Transaction::getContents() {
  return contents;
}

void Transaction::addMovie(Movie m){
  this->contents.push_back(m);
}

#include "transaction.h"


bool Transaction::isDue() const {
  return system_clock::to_time_t(system_clock::now()) == unixTimeDue;
}

uint64_t Transaction::unixTimeCheckedOut() const {
  return (uint64_t)unixTimeOfCheckout;
}

bool Transaction::contains(const Movie &arg) const {
  for(const Movie& itm : contents)if(arg.getTitle() == itm.getTitle())return
          true;
  return false;
}

std::vector<Movie> Transaction::getContents() {
  return contents;
}

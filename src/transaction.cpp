#include "transaction.h"


bool Transaction::isDue() const {
  return system_clock::to_time_t(system_clock::now()) == unixTimeDue;
}

uint64_t Transaction::unixTimeCheckedOut() const {
  return (uint64_t)unixTimeOfCheckout;
}

bool Transaction::contains(const Media &arg) const {
  for(const Media& itm : contents)if(arg.getTitle() == itm.getTitle())return true;
  return false;
}

std::vector<Media> Transaction::getContents() {
  return contents;
}

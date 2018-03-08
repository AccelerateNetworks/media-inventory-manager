
#ifndef MEDIA_INVENTORY_MANAGER_TRANSACTION_H
#define MEDIA_INVENTORY_MANAGER_TRANSACTION_H

#include <vector>
#include <chrono>
#include "movie.h"
using std::chrono::system_clock;
using std::chrono::duration;


/**
 * This is an Inventory support class that facilitates actions on the
 * Inventory object specific to calculating when objects need to be returned
 * to the inventory.
 */
class Transaction {
  
  /**
   * this is a private helper function for calculating the return due
   * date of a rental
   * @return the overly exact time and date that the rental is due
   */
  time_t calc_return_date (int num_days){
    using rental_length = std::chrono::duration<int,std::ratio<60*60*24>>;
    return system_clock::to_time_t(system_clock::now()+(rental_length()*num_days));
  };
  

  
  std::vector<Movie> contents;
  std::time_t unixTimeOfCheckout{system_clock::to_time_t(system_clock::now())};
  std::time_t unixTimeDue{calc_return_date(3)};
  
public:
  
  Transaction() = default;
  Transaction(int rental_length);
  
  bool isDue()const;
  uint64_t unixTimeCheckedOut()const;
  bool contains(const Movie& arg)const;
  std::vector<Movie> getContents();
  
  
};

#endif //MEDIA_INVENTORY_MANAGER_TRANSACTION_H

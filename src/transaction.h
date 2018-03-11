
#ifndef MEDIA_INVENTORY_MANAGER_TRANSACTION_H
#define MEDIA_INVENTORY_MANAGER_TRANSACTION_H

#include <vector>
#include <ctime>
#include <chrono>
#include "movie.h"


using namespace std::chrono;
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
   *
   * @param num_days A type double value for the number of days from now that
    * the inventory object is due to return.
   *
   * @return the overly exact time and date that the rental is due to return
   */
  time_t calc_return_date (int num_days){
    duration<long,std::ratio<60*60*24>> day(num_days);
    return system_clock::to_time_t(system_clock::now()+day);
  };
  

  
  std::vector<Movie*> contents;
  std::time_t unixTimeOfCheckout{system_clock::to_time_t(system_clock::now())};
  std::time_t unixTimeDue{calc_return_date(3)};
  
public:
  
  Transaction() = default;
  
  explicit Transaction(int rental_length);
  
  bool isDue()const;
  uint64_t unixTimeCheckedOut()const;
  bool contains(Movie& arg);
  std::vector<Movie*> getContents();
  void addMovie(Movie *);
  bool isReturned = false;
  
  
};

#endif //MEDIA_INVENTORY_MANAGER_TRANSACTION_H

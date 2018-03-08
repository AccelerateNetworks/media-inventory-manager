//
// Created by R.Peters on 3/8/2018.
//

#ifndef MEDIA_INVENTORY_MANAGER_TRANSACTION_H
#define MEDIA_INVENTORY_MANAGER_TRANSACTION_H

#include <vector>
#include <chrono>
#include "media.h"
using std::chrono::system_clock;
using std::chrono::duration;


/**
 * This is an Inventory support class that facilitates actions on the
 * Inventory object specific to calculating when objects need to be returned
 * to the inventory.
 */
class Transaction {
  
  /**
   * this private helper function is meant to healp in calculating a due date
   * for rentals relative to a starting epoch date.
   * @return a duration object that can be used in calculating time offsets
   * for due dates of rented inventory.
   */
  std::chrono::duration<int,std::ratio<60*60*24*3> > rental_length ();
  
  /**
   * this is also a private helper function for calculating the return due
   * date of a rental
   * @return the overly exact time and date that the rental is due
   */
  time_t calc_return_date (){
    return system_clock::to_time_t(system_clock::now()+rental_length());
  };

  std::vector<Media> contents;
  std::time_t unixTimeOfCheckout;
  std::time_t unixTimeDue;
  
public:

  bool isDue();
  uint64_t unixTimeCheckedOut();
  bool contains(const Media& arg);
  std::vector<Media> getContents();
  
  
};

#endif //MEDIA_INVENTORY_MANAGER_TRANSACTION_H

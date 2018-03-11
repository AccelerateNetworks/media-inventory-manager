#include <iostream>
#include <fstream>


#include "../client.h"
#include "../hashtable.h"
#include "../inventory.h"
#include "../media.h"
#include "../movie.h"
#include "../transaction.h"

using std::cout;
using std::endl;
using std::string;
using std::ifstream;

Inventory& command_input_file( Inventory& i);

int main () {
  std::cout << "this is where program output would be" << std::endl;
  return 0;
}

/**  We need to initialize the Inventory object outside of this function
 * so that the function doesn't need to change with any changes that happen
 * to Inventory in the future.
 *
 * @param i the Inventory object we'll be affecting with the commands from
 * the input file.
 *
 * @return the mutated Inventory object.
 */
Inventory& command_input_file( Inventory& i){
  ifstream inpfile = ifstream("../../docs/data4commands.txt");
  
}

/**  We need to initialize the Inventory object outside of this function
 * so that the function doesn't need to change with any changes that happen
 * to Inventory in the future.
 *
 * @param i the Inventory object we'll be affecting with the commands from
 * the input file.
 *
 * @return the mutated Inventory object.
 *
 */
Inventory& client_input_file( Inventory& i){
  ifstream inpfile = ifstream("../../docs/data4customers.txt");

}

/**  We need to initialize the Inventory object outside of this function
 * so that the function doesn't need to change with any changes that happen
 * to Inventory in the future.
 *
 * @param i the Inventory object we'll be affecting with the commands from
 * the input file.
 *
 * @return the mutated Inventory object.
 *
 */
Inventory& movie_input_file( Inventory& i){
  ifstream inpfile = ifstream("../../docs/data4movies.txt");

}


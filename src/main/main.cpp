#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

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
using std::vector;

Inventory& command_input_file( Inventory& i );
Inventory& client_input_file( Inventory& i );
Inventory& movie_input_file( Inventory& i );

int iHasher(int arg){
  return arg % 5;
}

HashTable<int, Client> clientLookup(iHasher);

int main () {

  Inventory i;

  command_input_file(movie_input_file(client_input_file(i))).printAllMedia();

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
  string line;
  while(std::getline(inpfile, line)){

    vector<string> tokens;
    string temp;

    // remove commas
    for(char c : line){
      if(c == ' ' || c == ','){
        if(!temp.empty()){
          tokens.push_back(temp);
          temp = "";
        }
      }

      temp += std::to_string(c);
    }


    switch(tokens[0].c_str[0]){
    case 'I': i.printAllMedia();
      break;
    case 'H':
      Client* c = clientLookup.get(tokens[1]);
      if(c == nullptr){
        cout << "Client does not exist!" << endl;
        break;
      }
      i.customerHistory(*c);
      break;
    case 'B':
      Client c = clientLookup.get(tokens[1]);
      if(c == nullptr){
        cout << "Client does not exist!" << endl;
        break;
      }
      if(tokens[2] != "D"){
        cout << "Invalid Media COde" << endl;
        break;
      }
      switch()

      break;
    case default:
      cout << "invalid input" << endl;
    }

  }

  return i;
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
  string line;
  while(std::getline(inpfile, line)){

    vector<string> tokens;
    string temp;

    // remove commas
    for(char c : line){
      if(c == ' ' || c == ','){
        if(!temp.empty()){
          tokens.push_back(temp);
          temp = "";
        }
      }

      temp += std::to_string(c);
    }

    for(string tok : tokens){
      // PROCESS COMMAND
    }
  }

  return i;
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
  string line;
  while(std::getline(inpfile, line)){

    vector<string> tokens;
    string temp;

    // remove commas
    for(char c : line){
      if(c == ' ' || c == ','){
        if(!temp.empty()){
          tokens.push_back(temp);
          temp = "";
        }
      }

      temp += std::to_string(c);
    }

    for(string tok : tokens){
      // PROCESS COMMAND
    }
  }

  return i;
}


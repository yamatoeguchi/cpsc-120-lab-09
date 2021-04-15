#include <algorithm>
#include <iostream>
#include <string>

#include "person.h"

using namespace std;

/// ErrorMessage prints out \p message first and then prints the standard
/// message
/// \code
/// "There was an error. Exiting.\n".
/// \endcode
///
/// \param message The programmer defined string that specifies the current
/// error.
void ErrorMessage(const string& message) {
  cout << message << "\n";
  cout << "There was an error. Exiting.\n";
}

/// Entry point to the address_book program
/// \remark This program takes no arguments. All the input is driven
/// by interactive prompts.
int main(int argc, char* argv[]) {
  /// Number of enteries in the address book.
  const int kEnteries = 3;
  /// The address book is C++ Vector object that contains Person objects.
  // TODO: declare a variable named address_book which is a vector of
  // Person objects.

  cout << "Let's add " << kEnteries << " to your address book!\n";
  for (int i = 0; i < kEnteries; i++) {
    // TODO: Print out a prompt for the computer user to enter a person's name
    // TODO: Declare a string variable named `name` to store the person's name.
    // TODO: Using getline(), read from cin and store into `name`; read up to
    // '\n'.

    // TODO: Print out a prompt for the computer user to enter a
    // person's phone number.
    // TODO: Declare a string variable named `phone_number` to store
    // the person's phone number.
    // TODO: Using getline(), read from cin and store into `phone_number`;
    // read up to '\n'.

    // TODO: Declare a variable named `p` which is of type Person. Intialize
    // it with the name and phone number that was read in from cin.
    // TODO: Use the push_back() method to insert into the vector the person
    // that was just created.
    // https://en.cppreference.com/w/cpp/container/vector/push_back
  }
  cout << "Let's sort your addressbook!\n";
  // TODO: Sort the address_book vector using sort().
  // https://en.cppreference.com/w/cpp/algorithm/sort

  cout << "Great! Let's print out all the enteries in your addressbook.\n";
  // TODO: Using a range-for loop, print out each entry of the addressbook.
  // Remember to use the overloaded << operator to output the person to
  // cout.

  return 0;
}

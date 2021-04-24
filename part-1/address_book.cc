// Yamato Eguchi
// CPSC-120-01
// 2021-04-23
// yamatoe1227@csu.fullerton.edu
// @yamatoeguchi
//
// Lab 09-01
//
// "This is my address_book.cc assignment"
//

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

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
  // declare a variable named address_book which is a vector of
  // Person objects.
  vector<Person> address_book;

  cout << "Let's add " << kEnteries << " to your address book!\n";
  for (int i = 0; i < kEnteries; i++) {
    // Print out a prompt for the computer user to enter a person's name
    cout << "Please enter a full name: ";
    // Declare a string variable named `name` to store the person's name.
    string name;
    // Using getline(), read from cin and store into `name`; read up to
    // '\n'.
    getline(cin, name, '\n');

    // Print out a prompt for the computer user to enter a
    // person's phone number.
    cout << "Please enter a phone number: ";
    // Declare a string variable named `phone_number` to store
    // the person's phone number.
    string phone_number;
    // Using getline(), read from cin and store into `phone_number`;
    // read up to '\n'.
    getline(cin, phone_number, '\n');

    // Declare a variable named `p` which is of type Person. Intialize
    // it with the name and phone number that was read in from cin.
    Person p(name, phone_number);
  
    // Use the push_back() method to insert into the vector the person
    // that was just created.
    // https://en.cppreference.com/w/cpp/container/vector/push_back
    address_book.push_back(p);
  }
  cout << "Let's sort your addressbook!\n";
  // Sort the address_book vector using sort().
  // https://en.cppreference.com/w/cpp/algorithm/sort
  sort(address_book.begin(), address_book.end());

  cout << "Great! Let's print out all the enteries in your addressbook.\n";

  // Using a range-for loop, print out each entry of the addressbook.
  // Remember to use the overloaded << operator to output the person to
  // cout.
  for(const auto& person : address_book) {
    cout << person << "\n";
  }

  return 0;
}

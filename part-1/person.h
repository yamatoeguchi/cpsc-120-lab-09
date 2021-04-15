/// A [header guard]
/// (https://google.github.io/styleguide/cppguide.html#The__define_Guard)
/// is used at the beginning of every header file. A
/// [header file]
/// (https://google.github.io/styleguide/cppguide.html#Header_Files)
/// is a file that contains the name of symbols (classes, structs,
/// functions, etc.) that are defined in an associated C++ source file.
/// The #ifndef is paired with a #endif at the end of the file.
#ifndef _PERSON_H_
#define _PERSON_H_

#include <iostream>
#include <string>

/// The Person class is an abstraction of a person.
/// If you think about the people you know, you'll realize that people
/// are very complicated and have a lot of details associated with them. For
/// example, people have height, weight, age, names, eye colors, favorite
/// colors, favorite foods, sports they like, addresses for home and work,
/// and a whole lot of other details. For our example program, we will
/// distill our idea of what a person is to two pieces of information.
/// In this case, a Person is represented by a \p name, and a \p phone_number.
/// In addtion to a person having only a \p name and a \p phone_number,
/// we will define a few details implicitly and some behaviors explicitly.
/// Implicitly, we are saying that all things that are of type Person
/// must have a \p name and a \p phone_number. It is impossible to create
/// a person without a a \p name and a \p phone_number. Secondly, once a
/// person object is created (born), the name can never be changed. A
/// person's \p phone_number can change though because there is a method
/// that can set the \p phone_number. Explicitly, we can compare persons to
/// one another because the boolean operators ==, !=, <, and > are defined.
/// This means we can easily sort people because we can compare them.
class Person {
 private:
  /// [Class data members]
  /// (https://google.github.io/styleguide/cppguide.html#Variable_Names)
  /// (variables that belong to a class) are named just like variables
  /// except that they end with an underscore ('_') character.
  std::string name_;
  std::string phone_number_;

 public:
  /// Person is a constructor which initializes a Person object
  /// \param name A string which represents the persons name like
  /// "Al Smith" or "Prince"
  /// \param phone_number A string which represents a telephone number like
  /// "657-278-3700"
  Person(std::string name, std::string phone_number);

  /// The name of the person
  /// \returns the name of the person
  std::string name() const;

  /// The phone_number of the person
  /// \returns the phone_number of the person
  std::string phone_number() const;

  /// Change the person's current phone_number to some other number
  /// \param phone_number The person's new phone number
  /// \returns The person object itself
  /// \remark The method returns the object itself so multiple methods
  /// can be chained together.
  Person& set_phone_number(const std::string& phone_number);

  /// Write the person object to an output stream
  /// \param out An output stream such as cout.
  /// \returns The outputput stream \p out
  /// \remark Look at operator<< at the bottom - this method is called from
  /// within that function.
  std::ostream& write(std::ostream& out) const;

  /// Boolean equals opertor overload
  /// \param person The operand to the right hand side of ==
  /// \returns true when *this and person have the same name and phone
  /// number.
  bool operator==(const Person& person) const;

  /// Boolean not equals operator overload
  /// \param person The operand to the right hand side of !=
  /// \returns true when *this and person do not have the same name and phone
  /// number.
  bool operator!=(const Person& person) const;

  /// Boolean less-than operator overload
  /// \param person The operand to the right hand side of <
  /// \returns true when *this.name() < person.name()
  bool operator<(const Person& person) const;

  /// Boolean greater-than operator overload
  /// \param person The operand to the right hand side of >
  /// \returns true when *this.name() > person.name()
  bool operator>(const Person& person) const;
};

/// Convert a person object into a string so it can be printed.
/// This is a function which defines a new behavior for the << operator.
/// \param out An output stream such as cout
/// \param person A person object
/// \remark This function is a wrapper for the Person::write() method.
std::ostream& operator<<(std::ostream& out, const Person& person);

// End of _PERSON_H_ header guard
#endif
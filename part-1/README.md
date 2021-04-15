# Address Book

Our first adventure using our own types is to create a simple address book. We will grossly simplify people down to two features, their names and phone numbers, and define a class named Person which represents an abstraction of what a person is.

We can imagine that if I collected a number of Person objects together I would have something of an address book. Using a C++ vector, we can store as many Person object's that we would like.
```c++
vector<Person> address_book;
```

The vector class is very flexible. If we tell it what type we would like to store in it, the vector magically reconfigures itself to store the specified type.

## Requirements

Implement any missing functionality in the Person class.

Using the Person class, create three person objects by prompting the user for a name and phone number for each person. Read the values from the terminal using the getline() function. Create Person objects and use push_back() to insert the objects into a vector of Person objects, the address book.

Once three persons have been inserted into the address book, sort the addressbook using the sort() function from the C++ Algorithms library.

Finally, use a range-for loop to print out the address book, thus verifying that the address book was sorted successfully using the sort() function.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* doc: generate HTML documentation from the source code using Doxygen
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* headercheck: check to make sure your files have the appropriate header

## Inline Documentation
The project is thoroughly documented inline using the [Doxygen](https://en.wikipedia.org/wiki/Doxygen) format. The documentation establishes a framework for you to follow so that you can implement all the details of the program. To generate HTML formatted documents to view on your computer use the make target `doc`. For example:

```
$ ls
Doxyfile	Makefile	README.md	find_min.cc
$ make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  find_min.cc \
	| sed 's/\(find_min\)\.o[ :]*/\1.o find_min.d : /g' > find_min.d; \
	[ -s find_min.d ] || rm -f find_min.d
doxygen Doxyfile
$ ls
Doxyfile	README.md	find_min.cc
Makefile	doc/		find_min.d
```

The inline documentation is saved in `doc/html`. To view the documentation, use the command `gio open doc/html/index.html` which will open the index file in your web browser.

If the `doxygen` command is not available, for instance when you use `make doc` the output looks like:

```
$ make doc
set -e; clang++ -MM -g -Wall -pipe -std=c++14  find_min.cc \
	| sed 's/\(find_min\)\.o[ :]*/\1.o find_min.d : /g' > find_min.d; \
	[ -s find_min.d ] || rm -f find_min.d
doxygen Doxyfile
make: doxygen: No such file or directory
make: *** [doc] Error 1
```

Then you can install `doxygen` using the command `sudo apt install doxygen doxygen-latex graphviz`.

## Don't Forget

Please remember that:

- You need to put a header in every file.
- You need to follow the [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html).
- Remove the `TODO` comments.

## Testing Your Code

Computers only ever do exactly what they are told, exactly the way they are told it, and never anything else. Testing is an important process to writing a program. You need to test for the program to behave correctly and test that the program behaves incorrectly in a predictable way.

As programmers we have to remember that there are a lot of ways that we can write the wrong program and only one to a few ways to write the correct program. We have to be aware of [cognitive biases](https://en.wikipedia.org/wiki/List_of_cognitive_biases) that we may exercise that lead us to believe we have correctly completed our program. That belief may be incorrect and our software may have errors. [Errors in software](https://www.wired.com/2005/11/historys-worst-software-bugs/) may lead to loss of [life](https://www.nytimes.com/2019/03/14/business/boeing-737-software-update.html), [property](https://en.wikipedia.org/wiki/Mariner_1), [reputation](https://en.wikipedia.org/wiki/Pentium_FDIV_bug), or [all of the above](https://en.wikipedia.org/wiki/2009%E2%80%9311_Toyota_vehicle_recalls).

### Test strategy

Start simple, and work your way up. Good tests are specific, cover a broad range of fundamentally different possibilities, can identify issues quickly, easily, and directly, without need for much set up, and can almost be diagnosed by inspection if the code fails to execute the test correctly.

## Example Output

Please ensure your program's output is identical to the example below.

```
$ make
set -e; clang++ -MM -g -Wall -pipe -std=c++14  person.cc \
	| sed 's/\(person\)\.o[ :]*/\1.o person.d : /g' > person.d; \
	[ -s person.d ] || rm -f person.d
set -e; clang++ -MM -g -Wall -pipe -std=c++14  address_book.cc \
	| sed 's/\(address_book\)\.o[ :]*/\1.o address_book.d : /g' > address_book.d; \
	[ -s address_book.d ] || rm -f address_book.d
clang++ -g -Wall -pipe -std=c++14  -c address_book.cc
clang++ -g -Wall -pipe -std=c++14  -c person.cc
clang++ -g -Wall -pipe -std=c++14 -o address_book address_book.o person.o 
$ ./address_book 
Let's add 3 to your address book!
Please enter a full name: Zeppo Marx
Please enter a phone number: 212-555-1212
Please enter a full name: Harpo Marx
Please enter a phone number: 213-555-1212
Please enter a full name: Groucho Marx
Please enter a phone number: 415-555-1212
Let's sort your addressbook!
Great! Let's print out all the enteries in your addressbook.
Groucho Marx 415-555-1212
Harpo Marx 213-555-1212
Zeppo Marx 212-555-1212
```


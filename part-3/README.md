# 3D Vector Class

If you're interested in creating computer graphics then a fundamental type that we need to use to represent points in space, directions in space, and colors is a 3D vector class.

You're provided with a rudamentary 3D vector class named Vec3. All you have to do is implement the various methods and functions to make the program work. The main function has already been written for you.

The sample output at the end of this README will appear once each method and function have been correctly implemented and the proper #includes have been placed in the the files.

## Requirements

Review the C++ source files and identify all the TODOs. Implement each method or function as specfied such that the main function executes correctly.

You can verify the correctness of the main function by verifying the output against the sample output and by verifying the math by hand.

To compile your program, you use the `make` command. A Makefile is provided for this exercise.

The Makefile has the following targets:
  
* all: builds the project
* clean: removes object and dependency files
* spotless: removes everything the clean target removes and all binaries
* doc: generate HTML documentation from the source code using Doxygen
* format: outputs a [`diff`](https://en.wikipedia.org/wiki/Diff) showing where your formatting differes from the [Google C++ style guide](https://google.github.io/styleguide/cppguide.html)
* tidy: output of the [linter](https://en.wikipedia.org/wiki/Lint_(software)) to give you tips on how to improve your code
* headercheck: check to make sure your files have the appropriate header
* *fetchfiles*: download sample animation files from textfiles.com

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
set -e; clang++ -MM -g -Wall -pipe -std=c++14  vec3.cc \
	| sed 's/\(vec3\)\.o[ :]*/\1.o vec3.d : /g' > vec3.d; \
	[ -s vec3.d ] || rm -f vec3.d
set -e; clang++ -MM -g -Wall -pipe -std=c++14  vec_demo.cc \
	| sed 's/\(vec_demo\)\.o[ :]*/\1.o vec_demo.d : /g' > vec_demo.d; \
	[ -s vec_demo.d ] || rm -f vec_demo.d
clang++ -g -Wall -pipe -std=c++14  -c vec_demo.cc
clang++ -g -Wall -pipe -std=c++14  -c vec3.cc
clang++ -g -Wall -pipe -std=c++14 -o vec_demo vec_demo.o vec3.o 
$ ./vec_demo 
zero == (0, 0, 0)
a == (1, 2, 3)
b == (3, 4, 5)
a + b == (4, 6, 8)
b - a == (2, 2, 2)
s == 3
b * s == (9, 12, 15)
s * b == (9, 12, 15)
a / s == (0.333333, 0.666667, 1)
dot(a, zero) == 0
dot(a, b) == 26
```


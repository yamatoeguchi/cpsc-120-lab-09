# Making Our First Image

Now that we know how to write to a file, let's try making a pretty image to look at.

We have gotten quite good at writing loops so let's try writing two nested for loops to come up with an interesting image.

We have an Image class which is an abstraction of the PPM image format. It is a really easy format to work with and it's a very unpopular format. For us it is ideal since we're just starting to work with files however we may have to install additional software on our computer to view the files. (Tips on what to install is at the end in the Example Output Section.)

We can imagine an image as being a grid and in each grid cell we can fill it with color. If we imagine the image as a grid then the grid has rows and columns. The rows are the cells that go from left to right and the columns are the cells that run from the top to the bottom.

Furthermore, an image has a width and a height expressed as an integer. If we say an image has 3 width and 2 height, then there are a total of 6 grid cells, 2 rows with 3 cells each, and 3 columns with 2 cells each.

Let's make an outer for loop which will count down the rows. The loop starts from the height - 1 and counts down towards 0. The inner loop counts the number of columns starting at 0 and counting up towards width.

Inside the loop, we will assign different colors to the 3 color channels, red, green, and blue. First with the red channel we will assign it the ratio of the current row / (width - 1). Then for the green channel we will assign it the ratio of the current columnt / height - 1. The blue channel will stay a consistent 0.25.

The values of the color channels are floating point values yet the PPM file format only works with integer values between 0 and 255. To convert our floating point values to numbers between 0 and 255, multiply the channel value against 255 and then use [lround()](https://en.cppreference.com/w/cpp/numeric/math/round) to round the number to the closest integer.

Finally, with the three channels computed, write the color value to the image using the write() method of the Image class.

## Requirements

Use the include Image class to create an image file in PPM format. The image output should be close to or identical to the example image given in the Example Output section.

Follow the instructions inside this README and the TODOs to complete the assignment.

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
set -e; clang++ -MM -g -Wall -pipe -std=c++14  image.cc \
	| sed 's/\(image\)\.o[ :]*/\1.o image.d : /g' > image.d; \
	[ -s image.d ] || rm -f image.d
set -e; clang++ -MM -g -Wall -pipe -std=c++14  image_hello_world.cc \
	| sed 's/\(image_hello_world\)\.o[ :]*/\1.o image_hello_world.d : /g' > image_hello_world.d; \
	[ -s image_hello_world.d ] || rm -f image_hello_world.d
clang++ -g -Wall -pipe -std=c++14  -c image_hello_world.cc
clang++ -g -Wall -pipe -std=c++14  -c image.cc
clang++ -g -Wall -pipe -std=c++14 -o image_hello_world image_hello_world.o image.o 
$ ./image_hello_world my_image.ppm
$ gm convert my_image.ppm my_image.png
$ gio open my_image.png
```

The image produced will look like the image included below.

### Sample Output Image, All Channels

![Sample output; image of a gradient.](sample_images/sample_image.png)

### Debugging Image, Red Channel Only

![Sample output, red channel only; image of a gradient.](sample_images/red.png)

### Debugging Image, Green Channel Only

![Sample output, green channel only; image of a gradient.](sample_images/green.png)

### Debugging Image, Blue Channel Only

![Sample output, blue channel only; image of a gradient.](sample_images/blue.png)

## Converting PPM Image Files

[Graphics Magick](http://www.graphicsmagick.org) is the recommended utility to convert images from one format to another. The command for Graphics Magick is `gm`. If your Linux installation is missing Graphics Magick package, you can easily install it using the commnd `sudo apt install graphicsmagick`.

To convert from a PPM to a PNG:

```
$ gm convert original_image.ppm converted_image.png
```

To convert from a PPM to a JPG or JPEG:

```
$ gm convert original_image.ppm converted_image.jpg
```


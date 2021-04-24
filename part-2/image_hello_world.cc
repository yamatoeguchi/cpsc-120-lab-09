// Yamato Eguchi
// CPSC-120-01
// 2021-04-23
// yamatoe1227@csu.fullerton.edu
// @yamatoeguchi
//
// Lab 09-02
//
// "This is my image_hello_world.cc assignment"
//

#include <cmath>
#include <iostream>
#include <sstream>
#include <string>

#include "image.h"

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

/// Entry point to the image_hello_world program
/// \remark Must have 1 argument. The argument is a path to a file. In the
/// simpliest case, it can be the name of a file in the same directory
/// as the program.
int main(int argc, char* argv[]) {
  if (argc < 2) {
    ErrorMessage("Please provide a path to a file.");
    exit(1);
  }

  // This declares a string variable that takes the first argument as its value.
  // the value is the output file name. this file is created if it 
  // does not exist in the directory. if it is, it overwrites the file so
  // be careful.
  string argv_one_output_file_name = string(argv[1]);

  // If you wish to change the size of the image, stick to square
  // dimensions and powers of 2. Remember the larger the width and height
  // the longer it will take to make the image and the more storage on
  // disk it will use.
  // Good choices are 256, 512, 1024, 2048, 4096, 8192
  const int kImageWidth = 256;
  const int kImageHeight = 256;

  Image image(argv_one_output_file_name, kImageWidth, kImageHeight);
  if (!image.is_open()) {
    // An output string stream is an object that defines a string that
    // can be changed while the program is running. Here, the string
    // is initialized with an error message and then the file name is
    // appended once the program is running.
    // https://en.cppreference.com/w/cpp/io/basic_stringstream/basic_stringstream
    ostringstream message_buffer("Could not open the file ", ios_base::ate);
    // String streams can use the same operators as cout and cin.
    message_buffer << argv_one_output_file_name << "!";
    // Convert the string stream to a string before passing it to
    // ErrorMessage().
    ErrorMessage(message_buffer.str());
    exit(1);
  }

  // Write an outer for loop for every row starting
  // at (image.height() - 1) and continuing while column is greater than
  // or equal to 0. Count down from (image.height() - 1) towards 0.
  for (int row = image.height() - 1; row >= 0; row--) {

    // Write an inner for loop for every row starting at 0 and
    // continuing while row is less than the image.width(). Count up
    // from 0 towards image.width().
    for (int column = 0; column < image.width(); column++) {

      // Body of the for loop...
      // First we will assign a red channel, then a green, and then a blue. The 
      // red and green channels will vary across the image while the blue channel
      // stays the same through out. Initially the values are assigned floating
      // point values and then they are converted to integers since our image
      // format only works with integer values between 0 and 255.
      // We use the function lround() to round the floating point numbers and
      // return integer values. Read more about lround() at 
      // https://en.cppreference.com/w/cpp/numeric/math/round.
      // Let's develop a plan for what to do in this loop...
      // 1. declare & assign double red and asssign it row / image.width() - 1
      // double red = 0;
      double red = double(column) / double(image.height() - 1);
      // 2. declare & assign double green and assign it column / image.height - 1
      // double green = 0;
      double green = double(row) / double(image.width() - 1);
      // 3. declare & assign double blue the value 0.25.
      double blue = 0.25;
      // 4. declare & assign int i_red to lround(255.0 * red)
      int i_red = lround(225.0 * red);
      // 5. declare & assign int i_green to lround(255.0 * green)
      int i_green = lround(255.0 * green);
      // 6. declare & assign int i_blue to lround(255.0 * blue)
      int i_blue = lround(255 * blue);
      // 7. Use image.write() to write the color into the image file.
      image.write(i_red, i_green, i_blue);
    }
  }

  image.close();

  return 0;
}


#include "image.h"

/// Initialize a new image file with the given path and dimensions.
/// \param file_name The path to the file to create
/// \param width The width of the image in pixels
/// \param height The height of the image in pixels
Image::Image(const std::string& file_name, int width, int height) {
  file_name_ = file_name;
  width_ = width;
  height_ = height;
  output_stream_ = std::ofstream(file_name_);
  if (is_open()) {
    output_stream_ << "P3\n";
    output_stream_ << "# The P3 means colors are in ACII, then the number\n";
    output_stream_ << "# of columns (" << width_ << ") and the number of\n";
    output_stream_ << "# rows (" << height_ << "), then 255 for the max\n";
    output_stream_ << "# color, then RGB triples.\n";
    output_stream_ << width_ << " " << height_ << "\n255\n";
  }
}

/// Check to see if the file is open and ready for pixel data.
/// \returns bool if the file stream is open else false
/// \remark If the file exists, then it will be deleted/truncated and
/// recreted. Be careful!
bool Image::is_open() { return output_stream_.is_open(); }

/// Write the pixel values red, green, and blue to the next scanline.
/// The values of \p red, \p green, and \p blue must be between 0 and 255.
/// \param red The red channel's value as an int. [0, 255]
/// \param green The green channel's value as an int. [0, 255]
/// \param blue The blue channel's value as an int. [0, 255]
void Image::write(int red, int green, int blue) {
  output_stream_ << red << " " << green << " "
                 << " " << blue << "\n";
}

/// Close the output file stream associated with the Image object
void Image::close() { output_stream_.close(); }

/// The width of the image in pixels
/// \returns The width of the image in pixels
int Image::width() const { return width_; }

/// The height of the image in pixels
/// \returns the height of the image in pixels
int Image::height() const { return height_; }
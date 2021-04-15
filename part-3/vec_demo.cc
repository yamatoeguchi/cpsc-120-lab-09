
#include <iostream>

using namespace std;

/// Entry point to the vec_demo program
/// \remark The program does not have any commad line arguments.
int main(int argc, char* argv[]) {
  // Declare three Vec3 variables, initialize each one to some values.
  Vec3 zero;
  Vec3 a(1, 2, 3);
  Vec3 b(3, 4, 5);
  
  // Print out each Vec3 to the terminal.
  cout << "zero == " << zero << "\n";
  cout << "a == " << a << "\n";
  cout << "b == " << b << "\n";

  // Sum the Vec3 a and b and save it in Vec3 c.
  Vec3 c = a + b;
  cout << "a + b == " << c << "\n";
  // Take the difference of Vec3 b and a and save it in Vec3 c
  c = b - a;
  cout << "b - a == " << c << "\n";
  
  // Define a scalar s.
  double s = 3.0;
  cout << "s == " << s << "\n";
  
  // Multiply the Vec3 b by the scalar s.
  c = b * s;
  cout << "b * s == " << c << "\n";
  // Multiply the Vec3 b by the scalar s.
  c = s * b;
  cout << "s * b == " << c << "\n";
  // Divide the Vec3 a by the scalar s.
  c = a / s;
  cout << "a / s == " << c << "\n";
  
  // Calculate the dot product between Vec3 a and Vec3 zero 
  double d = dot(a, zero);
  cout << "dot(a, zero) == " << d << "\n";
  // Calculate the dot product between Vec3 a and Vec3 b 
  d = dot(a, b);
  cout << "dot(a, b) == " << d << "\n";
  
  return 0;
}

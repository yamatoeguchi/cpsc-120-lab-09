
#include "vec3.h"

/// Return the value of x
/// \returns the value of x_
double Vec3::x() const {
  // TODO: Implement x()
}

/// Return the value of y
/// \returns the value of y_
double Vec3::y() const {
  // TODO: Implement y()
}

/// Return the value of z
/// \returns the value of z_
double Vec3::z() const {
  // TODO: Implement z()
}

/// Convert a Vec3 object into a string so it can be printed.
/// This is a function which defines a new behavior for the << operator.
/// \param out An output stream such as cout
/// \param person A Vec3 object
std::ostream& operator<<(std::ostream& out, const Vec3& v) {
  // TODO: Implement <<
  return out;
}

/// Sum \p u and \p v together
/// \param u The left hand operand of the operator
/// \param v The right hand operand of the operator
/// \returns The sum of \p u and \p v as a new Vec3.
Vec3 operator+(const Vec3& u, const Vec3& v) {
  // TODO: Implement +
}

/// Difference of \p u and \p v together
/// \param u The left hand operand of the operator
/// \param v The right hand operand of the operator
/// \returns The difference of \p u and \p v as a new Vec3.
Vec3 operator-(const Vec3& u, const Vec3& v) {
  // TODO: Implement -
}

/// Product of \p t and \p v
/// Where \p t is a scalar value and \p v is a Vec3, scale \p v with \p t.
/// \param t The left hand operand of the operator
/// \param v The right hand operand of the operator
/// \returns The product of \p t and \p v as a new Vec3.
Vec3 operator*(double t, const Vec3& v) {
  // TODO: Implement *
}

/// Product of \p v and \p t
/// Where \p t is a scalar value and \p v is a Vec3, scale \p v with \p t.
/// \param v The left hand operand of the operator
/// \param t The right hand operand of the operator
/// \returns The product of \p t and \p v as a new Vec3.
Vec3 operator*(const Vec3& v, double t) {
  // TODO: Implement *
}

/// Quotient of \p v and \p t
/// Where \p t is a scalar value and \p v is a Vec3, scale \p v with 1/t.
/// \param v The left hand operand of the operator
/// \param t The right hand operand of the operator
/// \returns The product of \p t and \p v as a new Vec3.
Vec3 operator/(const Vec3& v, double t) {
  // TODO: Implement *
}

/// The dot product of two Vec3 objects.
/// The [dot product](https://en.wikipedia.org/wiki/Dot_product) is
/// the cosine of the angle formed between the two Vec3 objects scaled by
/// the magnitude of the Vec3.
/// \param u The left hand operand of the operator
/// \param v The right hand operand of the operator
/// \returns The dot product between u and v.
double dot(const Vec3& u, const Vec3& v) {
  // TODO: Implement dot
}

/// The cross product of two Vec3 objects.
/// The cross product of two vectors yields a third which is mutally
/// orthogonal to the first two.
// \param u The first vector.
// \param v The second vector.
Vec3 cross(const Vec3& u, const Vec3& v) {
  return Vec3(u.y() * v.z() - u.z() * v.y(), u.y() * v.x() - u.x() * v.z(),
              u.x() * v.y() - u.y() * v.x());
}

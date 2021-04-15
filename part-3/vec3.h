
#ifndef _VEC3_H_
#define _VEC3_H_

#include <cmath>
#include <iostream>

/// A 3 dimensional vector class to represent vectors, points, and colors
class Vec3{
private:
  double x_;
  double y_;
  double z_;
public:
  /// The default constructor for Vec3 creates a Vec3 initialized
  /// to a zero vector.
  Vec3() : x_(0.0), y_(0.0), z_(0.0){};
  Vec3(double x, double y, double z): x_(x), y_(y), z_(z) {};
  
  double x() const;
  double y() const;
  double z() const;
};

std::ostream& operator<<(std::ostream &out, const Vec3 &v);

Vec3 operator+(const Vec3& u, const Vec3& v);

Vec3 operator-(const Vec3& u, const Vec3& v);

Vec3 operator*(double t, const Vec3& v);

Vec3 operator*(const Vec3& v, double t);

Vec3 operator/(const Vec3& v, double t);

double dot(const Vec3& u, const Vec3& v);

Vec3 cross(const Vec3& u, const Vec3& v);

#endif
#pragma once

#include <math.h>

namespace dj {

class Vector3 {
public:
  double x, y, z;
  Vector3();
  Vector3(const Vector3 &a);
  Vector3(double nx, double ny, double nz);
  Vector3 & operator =(const Vector3 &a);
  bool operator ==(const Vector3 &a) const;
  bool operator !=(const Vector3 &a) const;
  void zero();
  Vector3 operator -() const;
  Vector3 operator -(const Vector3 &a) const;
  Vector3 operator +(const Vector3 &a) const;
  Vector3 operator *(double a) const;
  Vector3 operator /(double a) const;
  Vector3 & operator +=(const Vector3 &a);
  Vector3 & operator -=(const Vector3 &a);
  Vector3 & operator *=(const Vector3 &a);
  Vector3 & operator /=(const Vector3 &a);
  // vector dot product
  double operator *(const Vector3 &a) const;
  void normalize();
};

// compute the magnitude of the vector
inline double vectorMag(const Vector3 &a) {
  return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

// compute the cross product of two vectors
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b) {
  return Vector3(
    a.y * b.z - a.z * b.y,
    a.z * b.x - a.x * b.z,
    a.x * b.y - a.y * b.x
  );
}

// scalar on the left multiplication, for symmetry
inline Vector3 operator *(double k, const Vector3 &v) {
  return Vector3(k * v.x, k * v.y, k * v.z);
}

// compute the distance between 2 points
inline double distance(const Vector3 &a, const Vector3 &b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  double dz = a.z - b.z;
  return sqrt(dx * dx + dy * dy + dz * dz);
}

const Vector3 kZeroVector(0, 0, 0);

} // namespace dj
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
inline double vectorMag(const Vector3 &a);

// compute the cross product of two vectors
inline Vector3 crossProduct(const Vector3 &a, const Vector3 &b);

// scalar on the left multiplication, for symmetry
inline Vector3 operator *(double k, const Vector3 &v);

// compute the distance between 2 points
inline double distance(const Vector3 &a, const Vector3 &b);

extern const Vector3 kZeroVector;
} // namespace dj
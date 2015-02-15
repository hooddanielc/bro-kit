#include <bro-kit/Vector3.h>

namespace dj {

Vector3::Vector3() {}
Vector3::Vector3(const Vector3 &a) : x(a.x), y(a.y), z(a.z) {}
Vector3::Vector3(double nx, double ny, double nz) : x(nx), y(ny), z(nz) {}

Vector3 & Vector3::operator =(const Vector3 &a) {
  x = a.x;
  y = a.y;
  z = a.z;
  return *this;
}

bool Vector3::operator ==(const Vector3 &a) const {
  return x == a.x && y == a.y && z == a.z;
}

bool Vector3::operator !=(const Vector3 &a) const {
  return a.x != x || y != a.y || z != a.z;
}

void Vector3::zero() {
  x = y = z = 0.0;
}

Vector3 Vector3::operator -() const {
  return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator -(const Vector3 &a) const {
  return Vector3(
    x - a.x,
    y - a.y,
    z - a.z
  );
}

Vector3 Vector3::operator +(const Vector3 &a) const {
  return Vector3 (
    x + a.x,
    y + a.y,
    z + a.z
  );
}

Vector3 Vector3::operator *(double a) const {
  return Vector3 (
    x * a,
    y * a,
    z * a
  );
}

Vector3 Vector3::operator /(double a) const {
  return Vector3(
    x / a,
    y / a,
    z / a
  );
}

Vector3 & Vector3::operator +=(const Vector3 &a) {
  x += a.x;
  y += a.y;
  z += a.z;
  return *this;
}

Vector3 & Vector3::operator -=(const Vector3 &a) {
  x -= a.x;
  y -= a.y;
  z -= a.z;
  return *this;
}

Vector3 & Vector3::operator *=(const Vector3 &a) {
  x *= a.x;
  y *= a.y;
  z *= a.z;
  return *this;
}

Vector3 & Vector3::operator /=(const Vector3 &a) {
  x /= a.x;
  y /= a.y;
  z /= a.z;
  return *this;
}

void Vector3::normalize() {
  double length = sqrt(x * x + y * y + z * z);

  if (length > 0.0) {
    x /= length;
    y /= length;
    z /= length;
  }
}

// vector dot product
double Vector3::operator *(const Vector3 &a) const {
  return x * a.x + y * a.y + z * a.z;
}

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

extern const Vector3 kZeroVector;

} // namespace dj
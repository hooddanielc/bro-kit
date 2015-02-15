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

} // namespace dj
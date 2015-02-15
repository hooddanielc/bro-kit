#include <lick.h>
#include <bro-kit/Vector3.h>

FIXTURE(intialization_x_y_z) {
  dj::Vector3 a(1, 2, 3);
  EXPECT_EQ(a.x, 1) << "x = 1";
  EXPECT_EQ(a.y, 2) << "y = 2";
  EXPECT_EQ(a.z, 3) << "z = 3";
}

FIXTURE(intialization_vector) {
  dj::Vector3 a(1, 2, 3);
  dj::Vector3 b(a);
  a.x = 5;
  a.y = 5;
  a.z = 5;
  EXPECT_EQ(a.x, 5);
  EXPECT_EQ(a.y, 5);
  EXPECT_EQ(a.z, 5);
  EXPECT_EQ(b.x, 1);
  EXPECT_EQ(b.y, 2);
  EXPECT_EQ(b.z, 3);
}

FIXTURE(condition_eq_eq) {
  dj::Vector3 a(1, 2, 3);
  dj::Vector3 b(1, 2, 3);
  EXPECT_TRUE(a == b);
}

FIXTURE(condition_not_eq) {
  dj::Vector3 a(1, 2, 3);
  dj::Vector3 b(3, 2, 1);
  EXPECT_TRUE(a != b);
}

FIXTURE(method_zero) {
  dj::Vector3 a(1, 2, 3);
  a.zero();
  EXPECT_EQ(a.x, 0);
  EXPECT_EQ(a.y, 0);
  EXPECT_EQ(a.z, 0);
}

FIXTURE(operator_minus) {
  dj::Vector3 a(1, 2, 3);
  dj::Vector3 b = -a;
  EXPECT_EQ(b.x, -1);
  EXPECT_EQ(b.y, -2);
  EXPECT_EQ(b.z, -3);
}

FIXTURE(operator_minus_vector) {
  dj::Vector3 a(5, 5, 5);
  dj::Vector3 b(3, 3, 3);
  dj::Vector3 c = a - b;
  EXPECT_EQ(c.x, 2);
  EXPECT_EQ(c.y, 2);
  EXPECT_EQ(c.z, 2);
}

FIXTURE(operator_plus_vector) {
  dj::Vector3 a(5, 5, 5);
  dj::Vector3 b(3, 3, 3);
  dj::Vector3 c = a + b;
  EXPECT_EQ(c.x, 8);
  EXPECT_EQ(c.y, 8);
  EXPECT_EQ(c.z, 8);
}

FIXTURE(operator_multiply_double) {
  dj::Vector3 a(5, 5, 5);
  dj::Vector3 b = a * 3;
  EXPECT_EQ(b.x, 15);
  EXPECT_EQ(b.y, 15);
  EXPECT_EQ(b.z, 15);
}

FIXTURE(operator_divide_double) {
  dj::Vector3 a(1, 1, 1);
  dj::Vector3 b = a / 4;
  EXPECT_EQ(b.x, 0.25);
  EXPECT_EQ(b.y, 0.25);
  EXPECT_EQ(b.z, 0.25);
}

FIXTURE(operator_plus_eq_vector) {
  dj::Vector3 a(1, 1, 1);
  dj::Vector3 b(2, 3, 4);
  a += b;
  EXPECT_EQ(a.x, 3);
  EXPECT_EQ(a.y, 4);
  EXPECT_EQ(a.z, 5);
}

FIXTURE(operator_minus_eq_vector) {
  dj::Vector3 a(1, 1, 1);
  dj::Vector3 b(2, 3, 4);
  a -= b;
  EXPECT_EQ(a.x, -1);
  EXPECT_EQ(a.y, -2);
  EXPECT_EQ(a.z, -3);
}

FIXTURE(operator_multiply_eq_vector) {
  dj::Vector3 a(2, 2, 2);
  dj::Vector3 b(2, 3, 4);
  a *= b;
  EXPECT_EQ(a.x, 4);
  EXPECT_EQ(a.y, 6);
  EXPECT_EQ(a.z, 8);
}

FIXTURE(operator_divide_eq_vector) {
  dj::Vector3 a(1, 1, 1);
  dj::Vector3 b(2, 4, 8);
  a /= b;
  EXPECT_EQ(a.x, 0.5);
  EXPECT_EQ(a.y, 0.25);
  EXPECT_EQ(a.z, 0.125);
}

FIXTURE(member_normalize) {
  dj::Vector3 a(0, 0, 5);
  a.normalize();
  EXPECT_EQ(a.x, 0);
  EXPECT_EQ(a.y, 0);
  EXPECT_EQ(a.z, 1);
  dj::Vector3 b(0, 5, 0);
  b.normalize();
  EXPECT_EQ(b.x, 0);
  EXPECT_EQ(b.y, 1);
  EXPECT_EQ(b.z, 0);
  dj::Vector3 c(5, 0, 0);
  c.normalize();
  EXPECT_EQ(c.x, 1);
  EXPECT_EQ(c.y, 0);
  EXPECT_EQ(c.z, 0);
}

FIXTURE(vector_magnitude) {
  dj::Vector3 a(0, 0, 1);
  EXPECT_EQ(1, dj::vectorMag(a));
}

FIXTURE(vector_dot_product) {
  dj::Vector3 a(12, 20, 0);
  dj::Vector3 b(16, -5, 0);
  EXPECT_EQ(92, a * b);
  dj::Vector3 c(7, 3, 1);
  dj::Vector3 d(8, 9, 4);
  EXPECT_EQ(87, c * d);
}

FIXTURE(vector_cross_product) {
  dj::Vector3 a(7, 3, 1);
  dj::Vector3 b(8, 9, 4);
  dj::Vector3 crossAB = crossProduct(a, b);
  EXPECT_EQ(crossAB.x, 3);
  EXPECT_EQ(crossAB.y, -20);
  EXPECT_EQ(crossAB.z, 39);
}

FIXTURE(lvalue_scalar) {
  dj::Vector3 a(1, 2, 3);
  double ok = 3;
  dj::Vector3 b = ok * a;
  EXPECT_EQ(b.x, 3);
  EXPECT_EQ(b.y, 6);
  EXPECT_EQ(b.z, 9);
}

FIXTURE(vector_distance) {
  dj::Vector3 a(1, 1, 1);
  dj::Vector3 b(1, 1, 2);
  EXPECT_EQ(distance(a, b), 1);
  dj::Vector3 c(4, 2, 4);
  dj::Vector3 d(9, 2, 4);
  EXPECT_EQ(distance(c, d), 5);
}

FIXTURE(zero_vector_constant) {
  dj::Vector3 a(1, 1, 1);
  EXPECT_EQ(0, dj::kZeroVector.x);
  EXPECT_EQ(0, dj::kZeroVector.y);
  EXPECT_EQ(0, dj::kZeroVector.z);
}

int main(int argc, char *argv[]) {
  return dj::lick::main(argc, argv);
}

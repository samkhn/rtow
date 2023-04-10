#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

class Vector3 {
 public:
  Vector3() : e_{0, 0, 0} {}
  Vector3(double e0, double e1, double e2) : e_{e0, e1, e2} {}

  double x() const { return e_[0]; };
  double y() const { return e_[1]; };
  double z() const { return e_[2]; };

  Vector3 operator-() const { return Vector3(-e_[0], -e_[1], -e_[2]); }
  double operator[](size_t i) const { return e_[i]; }
  double& operator[](size_t i) { return e_[i]; }

  Vector3& operator+=(const Vector3& v) {
    e_[0] += v.e_[0];
    e_[1] += v.e_[1];
    e_[2] += v.e_[2];
    return *this;
  }

  Vector3& operator*=(const double t) {
    e_[0] *= t;
    e_[1] *= t;
    e_[2] *= t;
    return *this;
  }

  Vector3& operator/=(const double t) { return *this *= 1 / t; }

  double Length() const {
    return std::sqrt(e_[0] * e_[0] + e_[1] * e_[1] + e_[2] * e_[2]);
  }

  // TODO: perhaps this should be private.
  double e_[3];
};

using Point3Space = Vector3;
using Color = Vector3;

inline std::ostream& operator<<(std::ostream& out, const Vector3& v) {
  return out << v.x() << ' ' << v.y() << ' ' << v.z();
}

inline Vector3 operator+(const Vector3& u, const Vector3& v) {
  return Vector3(u.x() + v.x(), u.y() + v.y(), u.z() + v.z());
}

inline Vector3 operator-(const Vector3& u, const Vector3& v) {
  return Vector3(u.x() - v.x(), u.y() - v.y(), u.z() - v.z());
}

inline Vector3 operator*(const Vector3& u, const Vector3& v) {
  return Vector3(u.x() * v.x(), u.y() * v.y(), u.z() * v.z());
}

inline Vector3 operator*(double u, const Vector3& v) {
  return Vector3(u * v.x(), u * v.y(), u * v.z());
}

inline Vector3 operator*(const Vector3& u, double v) { return v * u; }

inline Vector3 operator/(const Vector3& u, double v) { return (1 / v) * u; }

inline double Dot(const Vector3& u, const Vector3& v) {
  return u.x() * v.x() + u.y() * v.y() + u.z() * v.z();
}

inline Vector3 Cross(const Vector3& u, const Vector3& v) {
  return Vector3(u.y() * v.z() - u.z() * v.y(), u.z() * v.x() - u.x() * v.z(),
                 u.x() * v.y() - u.y() * v.x());
}

inline Vector3 Unit(const Vector3& v) { return v / v.Length(); }

#endif  // VEC3_H

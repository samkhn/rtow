#ifndef RAY_H
#define RAY_H

#include "vector3.hpp"

class Ray {
 public:
  Ray() {}
  Ray(const Point3Space& origin, const Vector3& direction)
      : origin_(origin), direction_(direction) {}

  Point3Space Origin() const { return origin_; }
  Vector3 Direction() const { return direction_; }

  Point3Space At(double time) const { return origin_ + time * direction_; }

  Point3Space origin_;
  Vector3 direction_;
};

#endif  // RAY_H

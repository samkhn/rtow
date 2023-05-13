#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include <cmath>

#include "hittable.hpp"
#include "vector3.hpp"

class Sphere : public Hittable {
 public:
  Sphere() {}
  Sphere(Point3Space center, double radius)
      : center_(center), radius_(radius){};
  virtual bool Hit(const Ray& ray, double t_min, double t_max,
                   HitRecord& record) const override {
    Vector3 oc = ray.Origin() - center_;
    auto a = Dot(ray.Direction(), ray.Direction());
    auto b = 2.0 * Dot(oc, ray.Direction());
    auto c = Dot(oc, oc) - radius_ * radius_;
    auto d = b * b - 4 * a * c;
    if (d < 0) {
      return false;
    }
    auto root = (-b - std::sqrt(d)) / (2.0 * a);
    if (root < t_min || root > t_max) {
      root = (-b + std::sqrt(d)) / a;
      if (root < t_min || root > t_max) {
        return false;
      }
    }
    record.t = root;
    record.p = ray.At(root);
    record.normal = (record.p - center_) / radius_;
    return true;
  }
  Point3Space center_;
  double radius_;
};

#endif  // CIRCLE_HPP

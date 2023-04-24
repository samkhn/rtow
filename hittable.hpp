#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.hpp"
#include "vector3.hpp"

struct HitRecord {
  double t;
  Point3Space p;
  Vector3 normal;
};

class Hittable {
 public:
  virtual bool Hit(const Ray& ray, double t_min, double t_max,
                   HitRecord& hit_record) const = 0;
};

#endif  // HITTABLE_H

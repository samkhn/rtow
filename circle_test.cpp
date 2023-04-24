#include "circle.hpp"

#include "hittable.hpp"
#include "ray.hpp"
#include "test_utilities.hpp"
#include "vector3.hpp"

int main() {
  Sphere s(Point3Space(0, 0, -2), 1.0);
  Ray intersecting = Ray(Point3Space(0, 0, 0), Vector3(0, 0, -1));
  HitRecord r;
  assert(s.Hit(intersecting, -10, 10, r));
  assert(TestUtilities::AlmostEqual(r.p.x(), 0));
  assert(TestUtilities::AlmostEqual(r.p.y(), 0));
  assert(TestUtilities::AlmostEqual(r.p.z(), -1.0));
  Ray not_intersecting = Ray(Point3Space(10, 10, 10), Vector3(0,0,1));
  assert(!s.Hit(not_intersecting, -10, 10, r));
  return 0;
}

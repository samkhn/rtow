#include "rtow/circle.hpp"

#include <gtest/gtest.h>

#include "rtow/hittable.hpp"
#include "rtow/ray.hpp"
#include "rtow/vector3.hpp"
#include "test_utilities.hpp"

TEST(CircleTest, ChecksRayIntersection) {
  Sphere s(Point3Space(0, 0, -2), 1.0);
  Ray intersecting = Ray(Point3Space(0, 0, 0), Vector3(0, 0, -1));
  HitRecord r;
  EXPECT_TRUE(s.Hit(intersecting, -10, 10, r));
  EXPECT_TRUE(TestUtilities::AlmostEqual(r.p.x(), 0));
  EXPECT_TRUE(TestUtilities::AlmostEqual(r.p.y(), 0));
  EXPECT_TRUE(TestUtilities::AlmostEqual(r.p.z(), -1.0));
  Ray not_intersecting = Ray(Point3Space(10, 10, 10), Vector3(0, 0, 1));
  EXPECT_FALSE(s.Hit(not_intersecting, -10, 10, r));
}

#include "rtow/ray.hpp"

#include <gtest/gtest.h>

#include "test_utilities.hpp"

TEST(RayTest, BasicConstruction) {
  using TestUtilities::AlmostEqual;

  Ray default_ray;
  Point3Space at_5 = default_ray.At(5);
  EXPECT_TRUE(AlmostEqual(at_5.x(), 0));
  EXPECT_TRUE(AlmostEqual(at_5.y(), 0));
  EXPECT_TRUE(AlmostEqual(at_5.z(), 0));

  Ray example({2, 2, -1}, {1, 1, 1});
  Point3Space example_at_10 = example.At(10);
  EXPECT_TRUE(AlmostEqual(example_at_10.x(), 12));
  EXPECT_TRUE(AlmostEqual(example_at_10.y(), 12));
  EXPECT_TRUE(AlmostEqual(example_at_10.z(), 9));
}

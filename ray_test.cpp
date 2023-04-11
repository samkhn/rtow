#include <cassert>

#include "ray.hpp"
#include "test_utilities.hpp"

int main() {
  using TestUtilities::AlmostEqual;

  Ray default_ray;
  Point3Space at_5 = default_ray.At(5);
  assert(AlmostEqual(at_5.x(), 0));
  assert(AlmostEqual(at_5.y(), 0));
  assert(AlmostEqual(at_5.z(), 0));

  Ray example({2, 2, -1}, {1, 1, 1});
  Point3Space example_at_10 = example.At(10);
  assert(AlmostEqual(example_at_10.x(), 12));
  assert(AlmostEqual(example_at_10.y(), 12));
  assert(AlmostEqual(example_at_10.z(), 9));

  return 0;
}

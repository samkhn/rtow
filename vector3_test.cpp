#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>

#include "vector3.hpp"

namespace TestUtilities {

bool AlmostEqual(double x, double y, int UnitsInLastPlace) {
  return std::fabs(x - y) <= std::numeric_limits<double>::epsilon() *
                                 std::fabs(x + y) * UnitsInLastPlace ||
         std::fabs(x - y) < std::numeric_limits<double>::min();
}

bool AlmostEqual(double x, double y) {
  return AlmostEqual(x, y, nextafter(x, y) - x);
}

}  // namespace TestUtilities

int main() {
  Vector3 default_constructed;
  assert(TestUtilities::AlmostEqual(default_constructed.e_[0], 0));
  assert(TestUtilities::AlmostEqual(default_constructed.e_[1], 0));
  assert(TestUtilities::AlmostEqual(default_constructed.e_[2], 0));
  assert(TestUtilities::AlmostEqual(default_constructed.x(), 0));
  assert(TestUtilities::AlmostEqual(default_constructed.y(), 0));
  assert(TestUtilities::AlmostEqual(default_constructed.z(), 0));

  Vector3 negated_default_constructed = -default_constructed;
  assert(TestUtilities::AlmostEqual(negated_default_constructed.e_[0], 0));
  assert(TestUtilities::AlmostEqual(negated_default_constructed.e_[1], 0));
  assert(TestUtilities::AlmostEqual(negated_default_constructed.e_[2], 0));
  assert(TestUtilities::AlmostEqual(negated_default_constructed.x(), 0));
  assert(TestUtilities::AlmostEqual(negated_default_constructed.y(), 0));
  assert(TestUtilities::AlmostEqual(negated_default_constructed.z(), 0));

  // TODO: test [] operator.

  Vector3 sample(1.0, 2.0, 3.0);
  assert(TestUtilities::AlmostEqual(sample.x(), 1));
  assert(TestUtilities::AlmostEqual(sample.y(), 2));
  assert(TestUtilities::AlmostEqual(sample.z(), 3));

  Vector3 negated_sample = -sample;
  assert(TestUtilities::AlmostEqual(negated_sample.x(), -1));
  assert(TestUtilities::AlmostEqual(negated_sample.y(), -2));
  assert(TestUtilities::AlmostEqual(negated_sample.z(), -3));

  sample *= -1.0;
  assert(TestUtilities::AlmostEqual(sample.x(), negated_sample.x()));
  assert(TestUtilities::AlmostEqual(sample.y(), negated_sample.y()));
  assert(TestUtilities::AlmostEqual(sample.z(), negated_sample.z()));

  sample /= -1;
  assert(TestUtilities::AlmostEqual(sample.x(), 1));
  assert(TestUtilities::AlmostEqual(sample.y(), 2));
  assert(TestUtilities::AlmostEqual(sample.z(), 3));

  assert(TestUtilities::AlmostEqual(sample.Length(), std::sqrt(14)));
  assert(!TestUtilities::AlmostEqual(sample.Length(), std::sqrt(10)));

  sample += negated_sample;
  assert(TestUtilities::AlmostEqual(sample.x(), 0));
  assert(TestUtilities::AlmostEqual(sample.y(), 0));
  assert(TestUtilities::AlmostEqual(sample.z(), 0));

  Vector3 sample1(1.0, 2.0, 3.0);
  Vector3 sample2(4.0, 5.0, 6.0);
  std::stringstream serialized_sample;
  serialized_sample << sample2;
  // Because we are working with 4.0 and aren't specifying precision, it'll
  // print 4.
  // TODO: double check the standard that this'll hold.
  assert(serialized_sample.str() == "4 5 6");

  Vector3 combined = sample1 + sample2;
  assert(TestUtilities::AlmostEqual(combined.x(), 5.0));
  assert(TestUtilities::AlmostEqual(combined.y(), 7.0));
  assert(TestUtilities::AlmostEqual(combined.z(), 9.0));

  Vector3 sub = combined - sample1;
  assert(TestUtilities::AlmostEqual(sub.x(), 4.0));
  assert(TestUtilities::AlmostEqual(sub.y(), 5.0));
  assert(TestUtilities::AlmostEqual(sub.z(), 6.0));

  Vector3 scalar_mult = sub * 2;
  assert(TestUtilities::AlmostEqual(scalar_mult.x(), 8.0));
  assert(TestUtilities::AlmostEqual(scalar_mult.y(), 10.0));
  assert(TestUtilities::AlmostEqual(scalar_mult.z(), 12.0));

  scalar_mult = scalar_mult / 2;
  assert(TestUtilities::AlmostEqual(scalar_mult.x(), 4.0));
  assert(TestUtilities::AlmostEqual(scalar_mult.y(), 5.0));
  assert(TestUtilities::AlmostEqual(scalar_mult.z(), 6.0));

  Vector3 vec_mult = sample1 * sample2;
  assert(TestUtilities::AlmostEqual(vec_mult.x(), 4.0));
  assert(TestUtilities::AlmostEqual(vec_mult.y(), 10.0));
  assert(TestUtilities::AlmostEqual(vec_mult.z(), 18.0));

  assert(!TestUtilities::AlmostEqual(Dot(sample1, sample2), 21));
  assert(TestUtilities::AlmostEqual(Dot(sample1, sample2), 32));

  Vector3 cross = Cross(sample1, sample2);
  assert(TestUtilities::AlmostEqual(cross.x(), -3.0));
  assert(TestUtilities::AlmostEqual(cross.y(), 6.0));
  assert(TestUtilities::AlmostEqual(cross.z(), -3.0));

  Vector3 unit_sample2 = Unit(sample2);
  double d = std::sqrt(77);
  assert(TestUtilities::AlmostEqual(unit_sample2.x(), 4 / d));
  assert(TestUtilities::AlmostEqual(unit_sample2.y(), 5 / d));
  assert(TestUtilities::AlmostEqual(unit_sample2.z(), 6 / d));

  return 0;
}

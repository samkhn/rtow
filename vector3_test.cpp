#include <cassert>
#include <iomanip>
#include <iostream>
#include <sstream>

#include "test_utilities.hpp"
#include "vector3.hpp"

int main() {
  using TestUtilities::AlmostEqual;

  Vector3 default_constructed;
  assert(AlmostEqual(default_constructed.e_[0], 0));
  assert(AlmostEqual(default_constructed.e_[1], 0));
  assert(AlmostEqual(default_constructed.e_[2], 0));
  assert(AlmostEqual(default_constructed.x(), 0));
  assert(AlmostEqual(default_constructed.y(), 0));
  assert(AlmostEqual(default_constructed.z(), 0));

  Vector3 negated_default_constructed = -default_constructed;
  assert(AlmostEqual(negated_default_constructed.e_[0], 0));
  assert(AlmostEqual(negated_default_constructed.e_[1], 0));
  assert(AlmostEqual(negated_default_constructed.e_[2], 0));
  assert(AlmostEqual(negated_default_constructed.x(), 0));
  assert(AlmostEqual(negated_default_constructed.y(), 0));
  assert(AlmostEqual(negated_default_constructed.z(), 0));

  // TODO: test [] operator.

  Vector3 sample(1.0, 2.0, 3.0);
  assert(AlmostEqual(sample.x(), 1));
  assert(AlmostEqual(sample.y(), 2));
  assert(AlmostEqual(sample.z(), 3));

  Vector3 negated_sample = -sample;
  assert(AlmostEqual(negated_sample.x(), -1));
  assert(AlmostEqual(negated_sample.y(), -2));
  assert(AlmostEqual(negated_sample.z(), -3));

  sample *= -1.0;
  assert(AlmostEqual(sample.x(), negated_sample.x()));
  assert(AlmostEqual(sample.y(), negated_sample.y()));
  assert(AlmostEqual(sample.z(), negated_sample.z()));

  sample /= -1;
  assert(AlmostEqual(sample.x(), 1));
  assert(AlmostEqual(sample.y(), 2));
  assert(AlmostEqual(sample.z(), 3));

  assert(AlmostEqual(sample.Length(), std::sqrt(14)));
  assert(!AlmostEqual(sample.Length(), std::sqrt(10)));

  sample += negated_sample;
  assert(AlmostEqual(sample.x(), 0));
  assert(AlmostEqual(sample.y(), 0));
  assert(AlmostEqual(sample.z(), 0));

  Vector3 sample1(1.0, 2.0, 3.0);
  Vector3 sample2(4.0, 5.0, 6.0);
  std::stringstream serialized_sample;
  serialized_sample << sample2;
  // Because we are working with 4.0 and aren't specifying precision, it'll
  // print 4.
  // TODO: double check the standard that this'll hold.
  assert(serialized_sample.str() == "4 5 6");

  Vector3 combined = sample1 + sample2;
  assert(AlmostEqual(combined.x(), 5.0));
  assert(AlmostEqual(combined.y(), 7.0));
  assert(AlmostEqual(combined.z(), 9.0));

  Vector3 sub = combined - sample1;
  assert(AlmostEqual(sub.x(), 4.0));
  assert(AlmostEqual(sub.y(), 5.0));
  assert(AlmostEqual(sub.z(), 6.0));

  Vector3 scalar_mult = sub * 2;
  assert(AlmostEqual(scalar_mult.x(), 8.0));
  assert(AlmostEqual(scalar_mult.y(), 10.0));
  assert(AlmostEqual(scalar_mult.z(), 12.0));

  scalar_mult = scalar_mult / 2;
  assert(AlmostEqual(scalar_mult.x(), 4.0));
  assert(AlmostEqual(scalar_mult.y(), 5.0));
  assert(AlmostEqual(scalar_mult.z(), 6.0));

  Vector3 vec_mult = sample1 * sample2;
  assert(AlmostEqual(vec_mult.x(), 4.0));
  assert(AlmostEqual(vec_mult.y(), 10.0));
  assert(AlmostEqual(vec_mult.z(), 18.0));

  assert(!AlmostEqual(Dot(sample1, sample2), 21));
  assert(AlmostEqual(Dot(sample1, sample2), 32));

  Vector3 cross = Cross(sample1, sample2);
  assert(AlmostEqual(cross.x(), -3.0));
  assert(AlmostEqual(cross.y(), 6.0));
  assert(AlmostEqual(cross.z(), -3.0));

  Vector3 unit_sample2 = Unit(sample2);
  double d = std::sqrt(77);
  assert(AlmostEqual(unit_sample2.x(), 4 / d));
  assert(AlmostEqual(unit_sample2.y(), 5 / d));
  assert(AlmostEqual(unit_sample2.z(), 6 / d));

  return 0;
}

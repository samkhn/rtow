// TODO: test [] operator.

#include "rtow/vector3.hpp"

#include <gtest/gtest.h>

#include <iomanip>
#include <iostream>
#include <sstream>

#include "test_utilities.hpp"

using TestUtilities::AlmostEqual;

TEST(Vector3Test, DefaultConstructorIsZeroed) {
  Vector3 default_constructed;
  EXPECT_TRUE(AlmostEqual(default_constructed.e_[0], 0));
  EXPECT_TRUE(AlmostEqual(default_constructed.e_[1], 0));
  EXPECT_TRUE(AlmostEqual(default_constructed.e_[2], 0));
  EXPECT_TRUE(AlmostEqual(default_constructed.x(), 0));
  EXPECT_TRUE(AlmostEqual(default_constructed.y(), 0));
  EXPECT_TRUE(AlmostEqual(default_constructed.z(), 0));

  Vector3 negated_default_constructed = -default_constructed;
  EXPECT_TRUE(AlmostEqual(negated_default_constructed.e_[0], 0));
  EXPECT_TRUE(AlmostEqual(negated_default_constructed.e_[1], 0));
  EXPECT_TRUE(AlmostEqual(negated_default_constructed.e_[2], 0));
  EXPECT_TRUE(AlmostEqual(negated_default_constructed.x(), 0));
  EXPECT_TRUE(AlmostEqual(negated_default_constructed.y(), 0));
  EXPECT_TRUE(AlmostEqual(negated_default_constructed.z(), 0));
}

TEST(Vector3Test, BasicConstruction) {
  Vector3 sample(1.0, 2.0, 3.0);
  EXPECT_TRUE(AlmostEqual(sample.x(), 1));
  EXPECT_TRUE(AlmostEqual(sample.y(), 2));
  EXPECT_TRUE(AlmostEqual(sample.z(), 3));
}

TEST(Vector3Test, Length) {
  Vector3 sample(1.0, 2.0, 3.0);
  EXPECT_TRUE(AlmostEqual(sample.Length(), std::sqrt(14)));
  EXPECT_TRUE(!AlmostEqual(sample.Length(), std::sqrt(10)));
}

TEST(Vector3Test, NegationOperator) {
  Vector3 sample(1.0, 2.0, 3.0);

  Vector3 negated_sample = -sample;
  EXPECT_TRUE(AlmostEqual(negated_sample.x(), -1));
  EXPECT_TRUE(AlmostEqual(negated_sample.y(), -2));
  EXPECT_TRUE(AlmostEqual(negated_sample.z(), -3));

  sample += negated_sample;
  EXPECT_TRUE(AlmostEqual(sample.x(), 0));
  EXPECT_TRUE(AlmostEqual(sample.y(), 0));
  EXPECT_TRUE(AlmostEqual(sample.z(), 0));
}

TEST(Vector3Test, MultiplicationAndDivisionOperator) {
  Vector3 sample(1.0, 2.0, 3.0);
  Vector3 negated_sample(-1.0, -2.0, -3.0);

  sample *= -1.0;
  EXPECT_TRUE(AlmostEqual(sample.x(), negated_sample.x()));
  EXPECT_TRUE(AlmostEqual(sample.y(), negated_sample.y()));
  EXPECT_TRUE(AlmostEqual(sample.z(), negated_sample.z()));

  sample /= -1;
  EXPECT_TRUE(AlmostEqual(sample.x(), 1));
  EXPECT_TRUE(AlmostEqual(sample.y(), 2));
  EXPECT_TRUE(AlmostEqual(sample.z(), 3));
}

TEST(Vector3Test, Serialization) {
  Vector3 sample1(1.0, 2.0, 3.0);
  Vector3 sample2(4.0, 5.0, 6.0);
  std::stringstream serialized_sample;
  serialized_sample << sample2;
  // TODO: double check the standard that this'll hold.
  // Because we are working with 4.0 and aren't specifying precision, it'll
  // print 4.
  EXPECT_TRUE(serialized_sample.str() == "4 5 6");
}

TEST(Vector3Test, AdditionOperator) {
  Vector3 sample1(1.0, 2.0, 3.0);
  Vector3 sample2(4.0, 5.0, 6.0);

  Vector3 combined = sample1 + sample2;
  EXPECT_TRUE(AlmostEqual(combined.x(), 5.0));
  EXPECT_TRUE(AlmostEqual(combined.y(), 7.0));
  EXPECT_TRUE(AlmostEqual(combined.z(), 9.0));

  Vector3 sub = combined - sample1;
  EXPECT_TRUE(AlmostEqual(sub.x(), 4.0));
  EXPECT_TRUE(AlmostEqual(sub.y(), 5.0));
  EXPECT_TRUE(AlmostEqual(sub.z(), 6.0));
}

TEST(Vector3Test, ScalarMultiplicationAndDivision) {
  Vector3 sample(4.0, 5.0, 6.0);

  Vector3 scalar_mult = sample * 2;
  EXPECT_TRUE(AlmostEqual(scalar_mult.x(), 8.0));
  EXPECT_TRUE(AlmostEqual(scalar_mult.y(), 10.0));
  EXPECT_TRUE(AlmostEqual(scalar_mult.z(), 12.0));

  scalar_mult = scalar_mult / 2;
  EXPECT_TRUE(AlmostEqual(scalar_mult.x(), 4.0));
  EXPECT_TRUE(AlmostEqual(scalar_mult.y(), 5.0));
  EXPECT_TRUE(AlmostEqual(scalar_mult.z(), 6.0));
}

TEST(Vector3Test, VectorMultiplication) {
  Vector3 sample1(1.0, 2.0, 3.0);
  Vector3 sample2(4.0, 5.0, 6.0);

  Vector3 vec_mult = sample1 * sample2;
  EXPECT_TRUE(AlmostEqual(vec_mult.x(), 4.0));
  EXPECT_TRUE(AlmostEqual(vec_mult.y(), 10.0));
  EXPECT_TRUE(AlmostEqual(vec_mult.z(), 18.0));
}

TEST(Vector3Test, DotAndCrossProduct) {
  Vector3 sample1(1.0, 2.0, 3.0);
  Vector3 sample2(4.0, 5.0, 6.0);

  EXPECT_TRUE(!AlmostEqual(Dot(sample1, sample2), 21));
  EXPECT_TRUE(AlmostEqual(Dot(sample1, sample2), 32));

  Vector3 cross = Cross(sample1, sample2);
  EXPECT_TRUE(AlmostEqual(cross.x(), -3.0));
  EXPECT_TRUE(AlmostEqual(cross.y(), 6.0));
  EXPECT_TRUE(AlmostEqual(cross.z(), -3.0));
}

TEST(Vector3Test, UnitVector) {
  Vector3 sample(4.0, 5.0, 6.0);

  Vector3 unit_sample = Unit(sample);
  double d = std::sqrt(77);
  EXPECT_TRUE(AlmostEqual(unit_sample.x(), 4 / d));
  EXPECT_TRUE(AlmostEqual(unit_sample.y(), 5 / d));
  EXPECT_TRUE(AlmostEqual(unit_sample.z(), 6 / d));
}

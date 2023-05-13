#include "rtow/color.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <sstream>

TEST(ColorTest, PrintsColor) {
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  std::stringstream output;
  WriteColor(output, black);
  WriteColor(output, white);
  EXPECT_EQ(output.str(), "0 0 0\n255 255 255\n");
}
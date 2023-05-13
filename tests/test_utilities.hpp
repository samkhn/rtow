#ifndef TEST_UTILITIES_H
#define TEST_UTILITIES_H

#include <cmath>
#include <limits>

namespace TestUtilities {

inline bool AlmostEqual(double x, double y, int UnitsInLastPlace) {
  return std::fabs(x - y) <= std::numeric_limits<double>::epsilon() *
                                 std::fabs(x + y) * UnitsInLastPlace ||
         std::fabs(x - y) < std::numeric_limits<double>::min();
}

inline bool AlmostEqual(double x, double y) {
  return AlmostEqual(x, y, nextafter(x, y) - x);
}

}  // namespace TestUtilities

#endif  // TEST_UTILITIES_H

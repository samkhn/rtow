#include <cassert>
#include <iostream>
#include <sstream>

#include "color.hpp"

int main() {
  std::stringstream s;
  Color black(0, 0, 0);
  Color white(1, 1, 1);
  WriteColor(s, black);
  WriteColor(s, white);
  assert(s.str() == "0 0 0\n255 255 255\n");
  return 0;
}

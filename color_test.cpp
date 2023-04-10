#include <cassert>
#include <iostream>
#include <sstream>

#include "color.hpp"

int main() {
  std::stringstream s;
  Color black(0, 0, 0);
  Color white(255, 255, 255);
  WriteColor(s, black);
  WriteColor(s, white);
  assert(s.str() == "0 0 0\n65279 65279 65279\n");
  return 0;
}

#ifndef COLOR_H
#define COLOR_H

#include <cassert>
#include <iostream>

#include "vector3.hpp"

inline void WriteColor(std::ostream& out, const Color& pixel_color) {
  assert(pixel_color.x() >= 0 && pixel_color.x() <= 255);
  assert(pixel_color.y() >= 0 && pixel_color.y() <= 255);
  assert(pixel_color.z() >= 0 && pixel_color.z() <= 255);
  out << static_cast<int>(255.999 * pixel_color.x()) << ' '
      << static_cast<int>(255.999 * pixel_color.y()) << ' '
      << static_cast<int>(255.999 * pixel_color.z()) << '\n';
}

#endif  // COLOR_H

#include <iostream>

#include "color.hpp"
#include "ray.hpp"
#include "vector3.hpp"

Color RayColor(const Ray& ray) {
  Vector3 unit_direction = Unit(ray.Direction());
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main() {
  const auto aspect_ratio = 16.0 / 9.0;
  const int image_width = 400;
  const int image_height = static_cast<int>(image_width / aspect_ratio);

  auto viewport_height = 2.0;
  auto viewport_width = aspect_ratio * viewport_height;
  auto focal_length = 1.0;

  auto origin = Point3Space(0, 0, 0);
  auto horizontal = Vector3(viewport_width, 0, 0);
  auto vertical = Vector3(0, viewport_height, 0);
  auto lower_left_corner =
      origin - horizontal / 2 - vertical / 2 - Vector3(0, 0, focal_length);

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (int j = image_height - 1; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      auto u = double(i) / (image_width - 1);
      auto v = double(j) / (image_height - 1);
      Ray ray(origin,
              lower_left_corner + u * horizontal + v * vertical - origin);
      WriteColor(std::cout, RayColor(ray));
    }
  }
  std::cerr << "\nDone.\n";
  return 0;
}

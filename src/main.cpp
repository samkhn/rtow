#include <cstdint>
#include <iostream>

#include "rtow/circle.hpp"
#include "rtow/color.hpp"
#include "rtow/hittable.hpp"
#include "rtow/ray.hpp"
#include "rtow/vector3.hpp"

static Sphere s(Point3Space(0, 0, -1), 0.5);

Color RayColor(const Ray& ray) {
  HitRecord hit_record;
  if (s.Hit(ray, 0, 10, hit_record)) {
    return 0.5 * Color(hit_record.normal.x() + 1, hit_record.normal.y() + 1,
                       hit_record.normal.z() + 1);
  }
  Vector3 unit_direction = Unit(ray.Direction());
  auto t = 0.5 * (unit_direction.y() + 1.0);
  return (1.0 - t) * Color(1.0, 1.0, 1.0) + t * Color(0.5, 0.7, 1.0);
}

int main() {
  const double aspect_ratio = 16.0 / 9.0;
  const int32_t image_width = 400;
  const int32_t image_height = static_cast<int>(image_width / aspect_ratio);

  double viewport_height = 2.0;
  double viewport_width = aspect_ratio * viewport_height;
  double focal_length = 1.0;

  Point3Space origin = Point3Space(0, 0, 0);
  Vector3 horizontal = Vector3(viewport_width, 0, 0);
  Vector3 vertical = Vector3(0, viewport_height, 0);
  Vector3 lower_left_corner =
      origin - horizontal / 2 - vertical / 2 - Vector3(0, 0, focal_length);

  std::cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";
  for (int j = image_height; j >= 0; --j) {
    std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
    for (int i = 0; i < image_width; ++i) {
      double u = double(i) / (image_width - 1);
      double v = double(j) / (image_height - 1);
      Ray ray(origin,
              lower_left_corner + u * horizontal + v * vertical - origin);
      WriteColor(std::cout, RayColor(ray));
    }
  }
  std::cerr << "\nDone.\n";
  return 0;
}

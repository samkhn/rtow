# rtow

My walkthrough of [_Ray Tracing in One Weekend_](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

I've added unit tests.

This whole graphics thing? Kinda neat ey?

## Requirements

- CMake
- g++ or clang with C++14

## Run

Configure:
```bash
$ mkdir -p build
$ cmake -B build -G Ninja -S .
```

Run tests
```bash
$ cmake --build build
$ cd build && ctest
```

Generate image:
```bash
$ cmake --build build --target run-main
```
This generates an out directory and inside CMAKE_BUILD_DIR and produces an image.


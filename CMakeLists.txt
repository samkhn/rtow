cmake_minimum_required(VERSION 3.5)

project(rtow LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)  # Required for Google Test

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# rtow library

add_library(rtow INTERFACE)
target_include_directories(rtow INTERFACE include)

# Unit tests

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(vector3_test tests/vector3_test.cpp)
target_link_libraries(vector3_test GTest::gtest_main rtow)

add_executable(ray_test tests/ray_test.cpp)
target_link_libraries(ray_test GTest::gtest_main rtow)

add_executable(circle_test tests/circle_test.cpp)
target_link_libraries(circle_test GTest::gtest_main rtow)

add_executable(color_test tests/color_test.cpp)
target_link_libraries(color_test GTest::gtest_main rtow)

include(GoogleTest)
gtest_discover_tests(vector3_test)
gtest_discover_tests(ray_test)
gtest_discover_tests(circle_test)
gtest_discover_tests(color_test)

# rtow executable for rendering an image

add_executable(rtow_main src/main.cpp)
target_link_libraries(rtow_main PUBLIC rtow)

add_custom_target(sample-img
  DEPENDS rtow_main
  COMMAND $<TARGET_FILE:rtow_main> > ${PROJECT_BINARY_DIR}/image.ppm
  OUTPUT ${PROJECT_BINARY_DIR}/image.ppm
)



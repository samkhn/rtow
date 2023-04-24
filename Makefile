# rtow, Ray Tracing in One Weekend

export SHELL := /bin/bash -o pipefail

CXX_COMPILER = g++
CXX_FLAGS = -Wall -Werror -pedantic

BUILD_DIR := $(CURDIR)/build
OUT_DIR := $(CURDIR)/out

main := $(BUILD_DIR)/main
vector3_test := $(BUILD_DIR)/vector3_test
color_test := $(BUILD_DIR)/color_test
ray_test := $(BUILD_DIR)/ray_test
circle_test := $(BUILD_DIR)/circle_test

all: run_tests run

compile_commands: clean
	@bear -- make all

run_tests: run_vector3_test run_color_test run_ray_test run_circle_test

run_vector3_test: $(vector3_test)
	$<

$(vector3_test): vector3_test.cpp vector3.hpp test_utilities.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS) -g $< -o $@

run_color_test: $(color_test)
	$<

$(color_test): color_test.cpp color.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS) -g $< -o $@

run_ray_test: $(ray_test)
	$<

$(ray_test): ray_test.cpp ray.hpp test_utilities.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS) -g $< -o $@

run_circle_test: $(circle_test)
	$<

$(circle_test): circle_test.cpp circle.hpp test_utilities.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS) -g $< -o $@

run: $(main)
	@mkdir -p $(OUT_DIR)
	$(main) > $(OUT_DIR)/image.ppm

$(main): main.cpp color.hpp vector3.hpp circle.hpp
	@mkdir -p $(BUILD_DIR)
	$(CXX_COMPILER) $(CXX_FLAGS) -O2 $< -o $@

clean:
	@test -d $(BUILD_DIR) && rm -rf $(BUILD_DIR) || true
	@test -d $(OUT_DIR) && rm -rf $(OUT_DIR) || true

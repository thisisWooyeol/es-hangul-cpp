cmake_minimum_required(VERSION 3.14)

if(NOT DEFINED PROJECT_NAME)
  set(NOT_SUBPROJECT ON)
  # If EsHangulCpp is not being used as a subproject via `add_subdirectory`,
  # usually installation is required
  option(ESHANGULCPP_INSTALL "Build EsHangulCpp" ON)
else()
  set(NOT_SUBPROJECT OFF)
  # If EsHangulCpp is being used as a subproject via `add_subdirectory`,
  # chances are that the "main project" does not include EsHangulCpp headers
  # in any of its headers, in which case installation is not needed.
  option(ESHANGULCPP_INSTALL "Build EsHangulCpp (Projects embedding es-hangul-cpp may want to turn this OFF.)" OFF)
endif()

# Project options
option(ESHANGULCPP_BUILD_TESTING "Build tests" ON)
option(ESHANGULCPP_BUILD_BENCHMARKS "Build benchmarks" ON)
option(ESHANGULCPP_ENABLE_LINTERS "Enable Linters for the test builds" OFF)

project(EsHangulCpp LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
message(STATUS "C++ Standard set to C++${CMAKE_CXX_STANDARD}")

# Basic paths
set(BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})
set(SOURCE_DIR ${BASE_DIR}/src)
set(TEST_DIR ${BASE_DIR}/test)
set(BENCHMARK_DIR ${BASE_DIR}/benchmark) # Reserved for future use
message(STATUS "Base directory: ${BASE_DIR}")
message(STATUS "Source directory: ${SOURCE_DIR}")
message(STATUS "Test directory: ${TEST_DIR}")

# Add source directories
add_subdirectory(src)

# Build tests only if requested
if(ESHANGULCPP_BUILD_TESTING AND NOT_SUBPROJECT)
  include(CTest)
  enable_testing()
  add_subdirectory(test)
endif()

# Build benchmarks only if requested
if(ESHANGULCPP_BUILD_BENCHMARKS)
  add_subdirectory(benchmark)
endif()

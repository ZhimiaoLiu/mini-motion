cmake_minimum_required(VERSION 3.25)

project(
  mini_motion
  VERSION 0.1.0
  DESCRIPTION "A small multi-axis motion controller simulator"
  LANGUAGES CXX)

# Keep the build tree separate from the sources.
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds are not allowed. Use a CMake preset, e.g. `cmake --preset linux-debug`.")
endif()

set(CMAKE_CXX_EXTENSIONS OFF) # -std=c++23, not -std=gnu++23

option(MOTION_BUILD_TESTS "Build unit tests" ON)
option(MOTION_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" ON)
option(MOTION_ENABLE_SANITIZERS "Build everything with AddressSanitizer (+UBSan on GCC/Clang)" OFF)

include(cmake/ProjectOptions.cmake)

add_subdirectory(src)
add_subdirectory(apps/simulate)

if(MOTION_BUILD_TESTS)
  enable_testing()
  add_subdirectory(tests)
endif()

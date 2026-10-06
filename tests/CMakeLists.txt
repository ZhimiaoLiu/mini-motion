include(FetchContent)

FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
  SYSTEM # treat GoogleTest headers as system headers: our strict warnings don't apply to them
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # MSVC: match the default /MD runtime
set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
set(BUILD_GMOCK OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)

add_executable(motion_tests
  version_test.cpp
)
target_link_libraries(motion_tests PRIVATE motion::core GTest::gtest_main)
target_compile_definitions(motion_tests PRIVATE MOTION_EXPECTED_VERSION="${PROJECT_VERSION}")
motion_set_warnings(motion_tests)

gtest_discover_tests(motion_tests)

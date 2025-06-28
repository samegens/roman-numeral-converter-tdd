cmake_minimum_required(VERSION 3.15)
project(convert CXX)

set(sources src/RomanNumberConverter.cpp)
set(test_sources test/RomanNumberConverterTests.cpp)

# Enable coverage instrumentation for Debug builds
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  message(STATUS "Building with code coverage instrumentation")
  # Global compile and link flags for coverage
  add_compile_options(--coverage -O0 -g)
  add_link_options(--coverage)
endif()

add_executable(convert src/main.cpp ${sources})

# Unit tests
enable_testing()
find_package(GTest REQUIRED)
add_executable(unit_tests ${test_sources} ${sources})
target_include_directories(unit_tests PRIVATE src)
target_link_libraries(unit_tests PRIVATE GTest::gtest_main)
add_test(NAME unit_tests COMMAND unit_tests)

cmake_minimum_required(VERSION 3.21)
project(cli-rng
  VERSION 1.3.4
  LANGUAGES CXX
)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

include(GoogleTest)
add_library(rng_core rng.cpp)

add_executable(rng main.cpp)
target_link_libraries(rng PRIVATE rng_core)

enable_testing()

add_executable(rngTest tests/rngTest.cpp)
target_link_libraries(rngTest PRIVATE rng_core GTest::gtest_main)

gtest_discover_tests(rngTest)
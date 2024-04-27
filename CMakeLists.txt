cmake_minimum_required(VERSION 3.20)
project(dev_container)

set(CMAKE_CXX_STANDARD 20)

option(USE_CLANG_TIDY "Use clang" OFF)

if(USE_CLANG_TIDY)
     message(STATUS "Using clang-tidy")
     set(CMAKE_CXX_CLANG_TIDY clang-tidy
     --checks=modernize-*,readability-*,performance-*,-modernize-use-trailing-return-type
     --header-filter=.*
     --warnings-as-errors=*
     )
     add_compile_options(
          -Wunused-variable
          -Wunused-function
          -Wunused-parameter
          -Werror
     )
endif()

find_package(GTest REQUIRED)
find_package(Eigen3 REQUIRED)

add_library(mylib src/lib.cpp)
target_include_directories(mylib PUBLIC include)
target_link_libraries(mylib Eigen3::Eigen)

add_executable(main src/main.cpp)
target_link_libraries(main mylib)

# Testing
include(GoogleTest)
enable_testing()
add_executable(tests test/test_lib.cpp)
target_link_libraries(tests mylib GTest::gtest_main GTest::gmock)
gtest_discover_tests(tests)
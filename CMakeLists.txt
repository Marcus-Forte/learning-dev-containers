cmake_minimum_required(VERSION 3.20)
project(dev_container)

set(CMAKE_CXX_STANDARD 20)

# set(CMAKE_CXX_CLANG_TIDY clang-tidy
# -checks=*,-llvm*,-modernize-use-*,-google*,-readability-magic-numbers,-cppcoreguidelines-avoid-magic-numbers
# # -warnings-as-errors=*
# -header-filter=.*
# )

add_compile_options(
     -Wunused-variable
     -Werror
)

find_package(GTest REQUIRED)
find_package(Eigen3 REQUIRED)


add_library(mylib src/lib.cpp)
target_include_directories(mylib PUBLIC include)
target_link_libraries(mylib Eigen3::Eigen)

add_executable(main src/main.cpp)
target_link_libraries(main mylib)

# # format
# add_custom_command(TARGET main PRE_BUILD 
# COMMAND clang-format ARGS -i 
# "${CMAKE_SOURCE_DIR}/src/*.cpp"
# "${CMAKE_SOURCE_DIR}/include/*.h")

# Testing
include(GoogleTest)
enable_testing()
add_executable(tests test/test_lib.cpp)
target_link_libraries(tests mylib GTest::gtest_main GTest::gmock)
gtest_discover_tests(tests)
cmake_minimum_required(VERSION 3.14)
project(googletest_test)

include_directories(./googletest/googletest/include)
set(CMAKE_CXX_STANDARD 17)

link_directories(./googletest/build/lib)
add_executable(googletest_test main.cpp)

target_link_libraries(googletest_test gtest gtest_main pthread)
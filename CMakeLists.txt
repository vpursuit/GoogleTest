cmake_minimum_required(VERSION 3.14)
project(googletest_test)

include_directories(./googletest/googletest/include ./googletest/googlemock/include)
set(CMAKE_CXX_STANDARD 17)

################################
# Main
################################
add_executable(googletest_test src/main.cpp)
target_link_libraries(googletest_test)

################################
# Unit Tests
################################
link_directories(./googletest/build/lib)

# Add test cpp file
add_executable(runUnitTests src/Checkout.cpp src/test/CheckoutTest.cpp src/test/MockTest.cpp)

# Link test executable against gtest & gtest_main
target_link_libraries(runUnitTests gtest gmock gtest_main pthread)
add_test(runUnitTests runUnitTests)
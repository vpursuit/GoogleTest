# Test Google Test

A showcase howto
- add googletest as git submodul
- configure CMakeList.txt
- use it in Clion
- create some simple functional test using TEST_F (CheckoutTest.cpp)
- make use of mock object and expectations (Mocktest.cpp)

# Build instructions
````
git clone --recurse-submodules https://github.com/vpursuit/GoogleTest.git
make build 
cd build
cmake ../
make
googletest_test
````
# Test Google Test

A showcase howto
- add googletest as git submodu
- configure CMakeList.txt
- use it in Clion

# Build instructions
git clone --recurse-submodules https://github.com/vpursuit/GoogleTest.git
make build 
cd build
cmake ../
make
googletest_test
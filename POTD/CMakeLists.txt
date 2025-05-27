cmake_minimum_required(VERSION 3.10)
project(POTD)

# Full paths to both compilers
set(CMAKE_C_COMPILER "C:/msys64/mingw64/bin/clang.exe")
set(CMAKE_CXX_COMPILER "C:/msys64/mingw64/bin/clang++.exe")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-O3 -Wall")

add_executable(potd ../main.cpp)

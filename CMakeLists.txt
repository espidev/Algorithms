cmake_minimum_required(VERSION 3.8)
project(Algorithms)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES algorithms/c++/DFS.cpp solutions/c++/KnapSack.cpp)
add_executable(Algorithms ${SOURCE_FILES})
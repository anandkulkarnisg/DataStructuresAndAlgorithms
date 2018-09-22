cmake_minimum_required(VERSION 2.8.4)
project(SortUtils)

# Set up the build flags here.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -g -Wall")

# Generate shared library libSortUtils.so file.
ADD_LIBRARY(SortUtils SHARED SortUtils.cpp)

# Add the specific examples below.
add_executable(testMain.out testMain.cpp)
target_link_libraries(testMain.out SortUtils)

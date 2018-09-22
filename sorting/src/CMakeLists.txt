cmake_minimum_required(VERSION 2.8.4)
project(SortUtils)

# Set up the build flags here.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -g -Wall")

# Generate shared library libSortUtils.so file.
ADD_LIBRARY(SortUtils SHARED SortUtils.cpp)

# Add the specific examples below.
add_executable(testMain.out testMain.cpp)
target_link_libraries(testMain.out SortUtils)

# Add the unit Tests using the Boost Test Framework.
add_executable(BoostUnitTests.out BoostUnitTests.cpp)
target_include_directories(BoostUnitTests.out PRIVATE "${PWD}")
target_compile_options(BoostUnitTests.out PRIVATE "-DBOOST_TEST_DYN_LINK")
target_link_libraries(BoostUnitTests.out boost_unit_test_framework SortUtils)


# Add the Performance Test using the Boost Test Framework.
add_executable(BoostPerfTests.out BoostPerfTests.cpp)
target_include_directories(BoostPerfTests.out PRIVATE "${PWD}")
target_compile_options(BoostPerfTests.out PRIVATE "-DBOOST_TEST_DYN_LINK")
target_link_libraries(BoostPerfTests.out boost_unit_test_framework SortUtils)



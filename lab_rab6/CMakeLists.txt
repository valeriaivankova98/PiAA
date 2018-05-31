cmake_minimum_required(VERSION 2.8.12.2)

project(lab_rab6)

add_library(AKfunc src/AKfunc.cpp)

target_include_directories(AKfunc PUBLIC ./hdr)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

add_executable (AKStandart src/AKstandart.cpp)
add_executable (AKDjoker src/AKwithDJoker.cpp)

target_link_libraries(AKStandart AKfunc)
target_link_libraries(AKDjoker AKfunc)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(tests test/test.cpp)
target_link_libraries(tests AKfunc)
target_link_libraries(tests ${GTEST_LIBRARIES} pthread)
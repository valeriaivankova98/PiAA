cmake_minimum_required (VERSION 2.8)

project(algorithmKMP)

set(CMAKE_CXX_FLAGS "-Wall -std=c++11")

add_executable (kmp_run ./src/kmp.cpp)
add_executable (shift_run ./src/shift.cpp)
add_executable (test ./test/test.cpp)

add_library(MyLib ./src/Kmp_functions.cpp)

target_link_libraries(kmp_run MyLib)
target_link_libraries(shift_run MyLib)


include_directories(./include)

target_compile_features(MyLib PUBLIC cxx_std_11)

find_package(GTest REQUIRED)
target_include_directories(test PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(test PRIVATE ${GTEST_LIBRARIES} pthread MyLib)

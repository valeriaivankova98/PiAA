cmake_minimum_required (VERSION 3.11)

project(algorithmKMP)

set(CMAKE_CXX_FLAGS "-Wall -Werror -std=c++11")

add_executable (kmp_run ./src/kmp.cpp)
add_executable (shift_run ./src/shift.cpp)
add_executable (test_prefix ./test/test_prefix.cpp)
add_executable (test_kmp ./test/test_kmp.cpp)
add_executable (test_shift ./test/test_shift.cpp)

add_library(MyLib ./src/Kmp_functions.cpp)

target_link_libraries(kmp_run MyLib)
target_link_libraries(shift_run MyLib)


include_directories(./include)

target_compile_features(MyLib PUBLIC cxx_std_11)

find_package(GTest REQUIRED)
target_include_directories(test_prefix  PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(test_prefix  PRIVATE ${GTEST_LIBRARIES} pthread MyLib)

target_include_directories(test_kmp PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(test_kmp PRIVATE ${GTEST_LIBRARIES} pthread MyLib)

target_include_directories(test_shift PRIVATE ${GTEST_INCLUDE_DIRS})
target_link_libraries(test_shift PRIVATE ${GTEST_LIBRARIES} pthread MyLib)

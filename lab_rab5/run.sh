#!/bin/bash

rm -rf ./build
mkdir build
cd build
cmake ..
make
./test_prefix
./test_kmp
./test_prefix


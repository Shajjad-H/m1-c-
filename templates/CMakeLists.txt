cmake_minimum_required(VERSION "2.8")

project("Templates")

set(CMAKE_CXX_FLAGS "-std=c++11 -Wall -g -Isrc/hpp") # compiler version and compiler flags.

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_BUILD_TYPE Debug)

file(GLOB src
    "src/hpp/*.hpp"
    "src/cpp/*.cpp"
)

message(src)

add_executable(test ${src} src/tests/templateFunction.cpp)

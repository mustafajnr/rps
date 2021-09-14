cmake_minimum_required(VERSION 3.18)
project(rps)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(rpsl src/rpsl.m.cpp)


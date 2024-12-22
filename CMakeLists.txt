cmake_minimum_required(VERSION 3.31.2)

set(CMAKE_OSX_ARCHITECTURES "arm64")

set(This DSA-CPP)

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

enable_testing()

add_subdirectory(googletest)

add_subdirectory(src)

add_subdirectory(tests)
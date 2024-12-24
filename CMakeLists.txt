cmake_minimum_required(VERSION 3.31.2)

set(This DSA-CPP)

project(${This} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

# set_target_properties(This PROPERTIES LINKER_LANGUAGE CXX)

enable_testing()

add_subdirectory(googletest)

add_subdirectory(src)

add_subdirectory(tests)
cmake_minimum_required(VERSION 3.31.2)

set(This DSA-CPP)

set(Headers
    ArrayQueue.hpp
)

set(Sources
    ArrayQueue.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
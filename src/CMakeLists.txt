cmake_minimum_required(VERSION 3.31.2)

set(This DSA-CPP)

set(Headers
    ArrayQueue.hpp
    ArrayStack.hpp
    LinkedQueue.hpp
)

set(Sources
    ArrayQueue.cpp
    ArrayStack.cpp
    LinkedQueue.cpp
)

add_library(${This} STATIC ${Sources} ${Headers})
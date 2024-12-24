cmake_minimum_required(VERSION 3.31.2)

set(This DSA-CPP)

set(Sources
    BinarySearchTree.cpp
)

set(Headers
    BinarySearchTree.hpp
)

add_library(${This} STATIC ${Sources} ${Headers})
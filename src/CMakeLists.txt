cmake_minimum_required(VERSION 3.31.2)

set(This DSA-CPP)

set(Headers
    SinglyLinkedList.h
)

set(Sources
    SinglyLinkedList.cpp
)

add_library(${This} STATIC ${Headers} ${Sources})
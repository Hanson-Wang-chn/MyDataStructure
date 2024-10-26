cmake_minimum_required(VERSION 3.27)
project(CircularLinkedStack)

set(CMAKE_CXX_STANDARD 17)

add_executable(CircularLinkedStack main.cpp
        utility.h
        MyCircularLinkedList.h
        MyCircularLinkedList.cpp)

cmake_minimum_required(VERSION 3.27)
project(Linked_Stack)

set(CMAKE_CXX_STANDARD 17)

add_executable(Linked_Stack main.cpp
        utility.h
        Linked_Stack.h
        Linked_Stack.cpp)

cmake_minimum_required(VERSION 3.27)
project(LinkedStack)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkedStack main.cpp
        utility.h
        MyLinkedStack.h
        MyLinkedStack.cpp)

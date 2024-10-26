cmake_minimum_required(VERSION 3.27)
project(LinkedQueue)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkedQueue main.cpp
        utility.h
        MyLinkedQueue.h
        MyLinkedQueue.cpp)

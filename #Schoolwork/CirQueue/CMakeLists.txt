cmake_minimum_required(VERSION 3.27)
project(CirQueue)

set(CMAKE_CXX_STANDARD 17)

add_executable(CirQueue main.cpp
        utility.h
        MyQueue.h
        MyQueue.cpp)

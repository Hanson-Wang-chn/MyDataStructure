cmake_minimum_required(VERSION 3.27)
project(Demonstration)

set(CMAKE_CXX_STANDARD 17)

add_executable(Demonstration main.cpp
        utility.h
        utility.cpp
        MyQueue.h
        MyQueue.cpp)

cmake_minimum_required(VERSION 3.27)
project(LinkQueue)

set(CMAKE_CXX_STANDARD 17)

add_executable(LinkQueue main.cpp
        utility.h
        MyLinkedQueue.h
        MyLinkedQueue.cpp)

cmake_minimum_required(VERSION 3.27)
project(YSF)

set(CMAKE_CXX_STANDARD 17)

add_executable(YSF main.cpp
        utility.h
        MyCircularLinkedList.h
        MyCircularLinkedList.cpp)

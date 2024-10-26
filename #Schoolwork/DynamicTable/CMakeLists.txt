cmake_minimum_required(VERSION 3.27)
project(DynamicTable)

set(CMAKE_CXX_STANDARD 17)

add_executable(DynamicTable main.cpp
        utility.h
        MyLinkedList.h
        MyLinkedList.cpp
        Course.h
        Course.cpp
        utility.cpp
        courses.h
        courses.cpp)

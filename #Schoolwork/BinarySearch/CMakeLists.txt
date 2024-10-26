cmake_minimum_required(VERSION 3.27)
project(BinarySearch)

set(CMAKE_CXX_STANDARD 17)

add_executable(BinarySearch main.cpp
        Key.h
        Key.cpp
        List.cpp
        List.h
        Ordered_list.h
        Ordered_list.cpp
        Record.cpp
        Record.h)

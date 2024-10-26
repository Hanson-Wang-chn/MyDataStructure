cmake_minimum_required(VERSION 3.27)
project(SortableList)

set(CMAKE_CXX_STANDARD 17)

add_executable(SortableList main.cpp
        List.h
        List.cpp
        Record.h
        Record.cpp
        Sortable_list.h
        Sortable_list.cpp
)

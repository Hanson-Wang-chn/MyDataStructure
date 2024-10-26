cmake_minimum_required(VERSION 3.28)
project(Binary_Tree_Adjusted)

set(CMAKE_CXX_STANDARD 17)

add_executable(Binary_Tree_Adjusted main.cpp
        Binary_node.h
        Binary_tree.h
        Binary_tree.cpp
        Key.h
        Key.cpp
        Record.h
        Record.cpp
        MyQueue.h
        MyQueue.cpp
        MyStack.h
        MyStack.cpp
        utility.h
        Binary_node.cpp)

cmake_minimum_required(VERSION 3.27)
project(AVL_Tree)

set(CMAKE_CXX_STANDARD 17)

add_executable(AVL_Tree main.cpp
        AVL_node.cpp
        AVL_node.h
        AVL_tree.cpp
        AVL_tree.h
        Binary_node.cpp
        Binary_node.h
        Binary_tree.cpp
        Binary_tree.h
        Record.cpp
        Record.h
        Search_tree.cpp
        Search_tree.h
        MyStack.cpp
        MyStack.h
        utility.h)

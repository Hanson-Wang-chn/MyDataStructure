cmake_minimum_required(VERSION 3.27)
project(DoubleLinkList)

set(CMAKE_CXX_STANDARD 17)

add_executable(DoubleLinkList main.cpp
        Node.h
        Node.cpp
        LinkList.h
        LinkList.cpp)

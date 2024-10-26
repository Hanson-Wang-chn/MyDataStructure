cmake_minimum_required(VERSION 3.27)
project(BracketMat)

set(CMAKE_CXX_STANDARD 17)

add_executable(BracketMat main.cpp
        utility.h
        MyStack.h
        MyStack.cpp
        utility.cpp)

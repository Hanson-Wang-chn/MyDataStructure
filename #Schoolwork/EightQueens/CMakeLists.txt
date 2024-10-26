cmake_minimum_required(VERSION 3.27)
project(EightQueens)

set(CMAKE_CXX_STANDARD 17)

add_executable(EightQueens main.cpp
        EightQueens.h
        EightQueens.cpp
        utility.h)

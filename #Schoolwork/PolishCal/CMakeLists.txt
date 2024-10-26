cmake_minimum_required(VERSION 3.27)
project(PolishCal)

set(CMAKE_CXX_STANDARD 17)

add_executable(PolishCal main.cpp
        utility.h
        MyStack.h
        MyStack.cpp
        PolishCal.h
        PolishCal.cpp
        utility.cpp)

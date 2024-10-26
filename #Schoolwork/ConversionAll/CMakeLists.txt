cmake_minimum_required(VERSION 3.27)
project(ConversionAll)

set(CMAKE_CXX_STANDARD 17)

add_executable(ConversionAll main.cpp
        utility.h
        MyStack.h
        MyStack.cpp)

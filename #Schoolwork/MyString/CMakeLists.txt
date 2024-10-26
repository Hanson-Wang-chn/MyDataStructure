cmake_minimum_required(VERSION 3.28)
project(MyString)

set(CMAKE_CXX_STANDARD 17)

add_executable(MyString main.cpp
        NewString.cpp
        NewString.h)

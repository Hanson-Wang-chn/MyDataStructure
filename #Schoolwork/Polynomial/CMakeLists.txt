cmake_minimum_required(VERSION 3.27)
project(Polynomial)

set(CMAKE_CXX_STANDARD 17)

add_executable(Polynomial main.cpp
        utility.h
        MyLinkedStack.h
        MyLinkedStack.cpp
        MyLinkedQueue.h
        MyLinkedQueue.cpp
        Term.h
        Term.cpp
        Polynomial.h
        Polynomial.cpp
        utility.cpp)

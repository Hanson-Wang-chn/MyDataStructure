cmake_minimum_required(VERSION 3.27)
project(Airport)

set(CMAKE_CXX_STANDARD 17)

add_executable(Airport main.cpp
        utility.h
        MyQueue.h
        MyQueue.cpp
        Plane.h
        Plane.cpp
        Random.h
        Random.cpp
        Runway.h
        Runway.cpp
        utility.cpp)

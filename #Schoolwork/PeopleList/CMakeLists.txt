cmake_minimum_required(VERSION 3.28)
project(PeopleList)

set(CMAKE_CXX_STANDARD 17)

add_executable(PeopleList main.cpp
        Person.cpp
        Person.h
        Student.cpp
        Student.h
        Teacher.cpp
        Teacher.h
        Staff.cpp
        Staff.h
        List.cpp
        List.h)

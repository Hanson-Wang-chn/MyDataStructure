cmake_minimum_required(VERSION 3.27)
project(Hash_Table)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hash_Table main.cpp
        Hash_Table.cpp
        Hash_Table.h
        Key.cpp
        Key.h
        Record.cpp
        Record.h)

cmake_minimum_required(VERSION 3.21)
project(lab4)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(lab4
        Dictionar.cpp
        Dictionar.h
        IteratorDictionar.cpp
        IteratorDictionar.h
        main.cpp
        TestExtins.cpp
        TestExtins.h
        TestScurt.cpp
        TestScurt.h)

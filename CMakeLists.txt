cmake_minimum_required(VERSION 3.10)
project(OOP_5)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(OOP_5
        funkcijos.cpp
        funkcijos.h
        main.cpp)
add_executable(Testavimas
        funkcijos.cpp
        funkcijos.h
        testCases/test.cpp
        rezultatai.txt
        tekstas.txt )


cmake_minimum_required(VERSION 4.1)
project(Lampara)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lampara src/main.cpp
        src/vec3.h
        src/color.h)

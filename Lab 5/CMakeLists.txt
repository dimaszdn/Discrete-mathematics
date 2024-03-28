cmake_minimum_required(VERSION 3.27)
project(Discr)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Discr main.cpp
        inc/Func.h
        inc/Parameters.h
        inc/Coding.h)

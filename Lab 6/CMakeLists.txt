cmake_minimum_required(VERSION 3.27)
project(Lab_6)

include_directories(inc/)
set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_6 main.cpp
        inc/UserInput.h
        inc/Edge.h
        inc/Matrix.h
        inc/Graph.h)

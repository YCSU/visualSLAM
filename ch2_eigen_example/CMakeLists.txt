project( eigenExample )

cmake_minimum_required( VERSION 3.0 )

add_definitions(-std=c++11 -O3)

include_directories("/usr/include/eigen3")

add_executable( eigenExample eigenMatrix.cpp )
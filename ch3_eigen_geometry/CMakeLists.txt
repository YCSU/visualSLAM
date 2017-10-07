project( eigen_geometry )

cmake_minimum_required( VERSION 3.0 )

add_definitions(-std=c++11 -O3)

include_directories("/usr/include/eigen3")

add_executable( eigen_geometry eigen_geometry.cpp )

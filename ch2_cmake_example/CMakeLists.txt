project( HelloSLAM )

cmake_minimum_required( VERSION 3.0 )

add_definitions(-std=c++11 -O3)

add_library( hello libHelloSLAM.cpp )

# add_library( hello_shared SHARED libHelloSLAM.cpp )
add_executable( helloSLAM helloSLAM.cpp )

target_link_libraries( helloSLAM hello)



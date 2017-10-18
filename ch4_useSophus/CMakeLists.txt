cmake_minimum_required( VERSION 3.0 )
project( useSophus )

add_definitions(-std=c++11 -O3)

# include_directories("/usr/include/eigen3")
include_directories("/home/ycsu/visualSlam/ch4_useSophus/Sophus")

################################################################################
# Sophus source dir
set( Sophus_SOURCE_DIR "/home/ycsu/visualSlam/ch4_useSophus/Sophus")

################################################################################
# Sophus build dir
set( Sophus_DIR "/home/ycsu/visualSlam/ch4_useSophus/Sophus")

################################################################################
set( Sophus_INCLUDE_DIR  "/home/ycsu/visualSlam/ch4_useSophus/Sophus;/usr/include/eigen3" )
set( Sophus_INCLUDE_DIRS  "/home/ycsu/visualSlam/ch4_useSophus/Sophus;/usr/include/eigen3" )

set( Sophus_LIBRARIES    "/home/ycsu/visualSlam/ch4_useSophus/Sophus/libSophus.so" )
set( Sophus_LIBRARY      "/home/ycsu/visualSlam/ch4_useSophus/Sophus/libSophus.so" )

set( Sophus_LIBRARY_DIR  "/home/ycsu/visualSlam/ch4_useSophus/Sophus" )
set( Sophus_LIBRARY_DIRS "/home/ycsu/visualSlam/ch4_useSophus/Sophus" )

#find_package( Sophus REQUIRED )
include_directories( ${Sophus_INCLUDE_DIRS} )

add_executable( useSophus useSophus.cpp )
target_link_libraries( useSophus ${Sophus_LIBRARIES} )
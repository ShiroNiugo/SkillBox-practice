# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)
# Add source to this project's executable.
add_executable (CMakeTarget simulatorOfOperations.cpp ${MY_INCLUDE_DIR}/command.h)
target_include_directories(CMakeTarget PUBLIC ${MY_INCLUDE_DIR})


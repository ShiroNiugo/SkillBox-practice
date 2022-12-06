# CMakeList.txt : CMake project for computerOperationSimulator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (computerOperationSimulator "src/main.cpp" "cpu.h" "ram.h" "disk.h" "gpu.h" "kbd.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET computerOperationSimulator PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

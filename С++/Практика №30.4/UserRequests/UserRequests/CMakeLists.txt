﻿# CMakeList.txt : CMake project for UserRequests, include source and define
# project specific logic here.
#

# Add source to this project's executable.
add_executable (UserRequests "src/UserRequests.cpp" "get.h" "patch.h")

target_link_libraries(UserRequests PRIVATE cpr::cpr)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET UserRequests PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.

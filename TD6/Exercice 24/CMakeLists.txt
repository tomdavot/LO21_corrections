cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

include_directories(.)

add_executable(TD6 main.cpp
  graph.h graph.cpp)

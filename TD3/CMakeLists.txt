cmake_minimum_required(VERSION 3.16)
project(ContigConsensus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

include_directories(.)

add_executable(Fraction main.cpp  fraction.h fraction.cpp)

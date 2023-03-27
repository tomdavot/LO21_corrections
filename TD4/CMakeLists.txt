cmake_minimum_required(VERSION 3.16)
project(ContigConsensus)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

include_directories(.)

add_executable(TD4 main.cpp set.h set.cpp
carte.h carte.cpp jeu.h jeu.cpp pioche.h pioche.cpp
plateau.h plateau.cpp combinaison.h combinaison.cpp controleur.h controleur.cpp)

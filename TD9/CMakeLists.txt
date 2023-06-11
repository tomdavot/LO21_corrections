cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

include_directories(.)


add_executable(TD10 main.cpp
		    agenda.h	agenda.cpp
		      evenement.h evenement.cpp
		      timing.h timing.cpp
		      logexception.cpp logexception.h
		    mylog.h mylogobjet.cpp mylogobjet.h log.h mylog.cpp)		        

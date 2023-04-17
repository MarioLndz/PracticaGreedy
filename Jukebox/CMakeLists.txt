cmake_minimum_required(VERSION 3.23)
project(Jukebox)

include_directories(include)

set(CMAKE_CXX_STANDARD 20)

add_executable(Jukebox src/main.cpp include/Cancion.h src/Cancion.cpp)

cmake_minimum_required(VERSION 3.23)
project(Jukebox)

include_directories(include)

set(CMAKE_CXX_STANDARD 20)

add_executable(Jukebox src/main.cpp include/Cancion.h src/Cancion.cpp)
add_executable(Generador src/generador.cpp)

add_executable(Pvc1 src/pvc1.cpp)
add_executable(Pvc2 src/pvc2.cpp)
add_executable(Pvc3 src/pvc3.cpp)

add_executable(Generador-pvc src/generador-pvc.cpp)
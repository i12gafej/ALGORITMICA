
cmake_minimum_required(VERSION 3.0)

project(p1)

file(GLOB SOURCES "*.cpp")

add_executable(p1 ${SOURCES})

target_compile_features(p1 PRIVATE cxx_std_11)

#ESCRIBA "cmake ." y "make" EN ESTA RUTA PARA COMPILARLO
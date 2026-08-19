cmake_minimum_required(VERSION 4.0)

project(Chess)

add_executable(Chess main.cpp myChessFunctions.cpp)

target_compile_options(Chess PRIVATE -ggdb3)

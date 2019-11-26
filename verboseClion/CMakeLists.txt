cmake_minimum_required(VERSION 3.15)
project(untitled C)

set(CMAKE_C_STANDARD 99)
set(SOURCE_FILES untitled main.c)
add_executable(untitled main.c readAll.c readAll.h readPart.c readPart.h create.c create.h)
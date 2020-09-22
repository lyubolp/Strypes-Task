cmake_minimum_required(VERSION 3.17)
project(StrypesTask C)

set(CMAKE_C_STANDARD 99)

add_library(StrypesTask SHARED library.c library.h queue.h queue.c point.c point.h)
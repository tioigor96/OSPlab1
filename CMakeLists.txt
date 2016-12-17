cmake_minimum_required(VERSION 3.6)
project(progettoC)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c11")

set(SOURCE_FILES main.c src/readlines.c libs/readlines.h libs/optionControl.h src/optionControl.c src/text_stats.c libs/text_stats.h)
add_executable(progettoC ${SOURCE_FILES})
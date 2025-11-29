cmake_minimum_required(VERSION 3.25)
project(binary_representation C)

add_library(binlib src/binary_representation/binlib.c)

add_executable(binary_representation src/binary_representation/main.c)
target_link_libraries(binary_representation PRIVATE binlib)
target_compile_options(binary_representation PRIVATE -Wall -Wextra -pedantic)

cmake_minimum_required(VERSION 3.25)

# Hello World
project(hello_world C)

add_executable(hello_world src/hello_world/hello_world.c)
target_compile_options(hello_world PRIVATE -Wall -Wextra -pedantic)

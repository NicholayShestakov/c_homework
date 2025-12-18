cmake_minimum_required(VERSION 3.25)
project(C_homework C)
add_compile_options(-Wall -Wextra -pedantic)

# Libraries

# Executables and links with libraries
add_executable(hello_world src/hello_world/hello_world.c)

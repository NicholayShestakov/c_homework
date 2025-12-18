cmake_minimum_required(VERSION 3.25)
project(C_homework C)
add_compile_options(-Wall -Wextra -pedantic)

# Libraries
add_library(stack src/stack_and_queue/stack/stack.c)

# Executables and links with libraries
add_executable(hello_world src/hello_world/hello_world.c)

add_executable(sorting_station src/stack_and_queue/stack/sorting_station.c)
target_link_libraries(sorting_station PRIVATE stack)

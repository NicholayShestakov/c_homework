cmake_minimum_required(VERSION 3.25)
project(sorting_station C)

add_library(stack src/stack_and_queue/stack/stack.c)

add_executable(sorting_station src/stack_and_queue/stack/sorting_station.c)
target_link_libraries(sorting_station PRIVATE stack)
target_compile_options(sorting_station PRIVATE -Wall -Wextra -pedantic)

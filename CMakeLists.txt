cmake_minimum_required(VERSION 3.25)
project(C_homework C)

# Libraries
add_library(stack src/stack_and_queue/stack/stack.c)

# Executables and links with libraries
add_executable(advanced_bracket_balance src/stack_and_queue/stack/advanced_bracket_balance.c)
target_link_libraries(advanced_bracket_balance PRIVATE stack)

add_executable(sorting_station src/stack_and_queue/stack/sorting_station.c)
target_link_libraries(sorting_station PRIVATE stack)


target_compile_options(all_executables PUBLIC -Wall -Wextra -pedantic)

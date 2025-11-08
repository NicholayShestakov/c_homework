cmake_minimum_required(VERSION 3.25)
project(advanced_bracket_balance C)

add_library(stack src/stack_and_queue/stack/stack.c)

add_executable(advanced_bracket_balance src/stack_and_queue/stack/advanced_bracket_balance.c)
target_link_libraries(advanced_bracket_balance PRIVATE stack)
target_compile_options(advanced_bracket_balance PRIVATE -Wall -Wextra -pedantic)

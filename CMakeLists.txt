cmake_minimum_required(VERSION 3.25)

# Advanced bracket balance
project(advanced_bracket_balance C)

add_library(stack src/stack_and_queue/stack/stack.c)

add_executable(advanced_bracket_balance src/stack_and_queue/stack/advanced_bracket_balance.c)
target_link_libraries(advanced_bracket_balance PRIVATE stack)
target_compile_options(advanced_bracket_balance PRIVATE -Wall -Wextra -pedantic)

# Purely functional queue test
project(purely_functional_queue_test C)

add_library(purely_functional_queue src/control_work_2/purely_functional_queue/purely_functional_queue.c)

add_executable(purely_functional_queue_test src/control_work_2/purely_functional_queue/test.c)
target_link_libraries(purely_functional_queue_test PRIVATE purely_functional_queue)
target_compile_options(purely_functional_queue PRIVATE -Wall -Wextra -pedantic)

# Comparsion
project(comparsion C)

add_executable(comparsion src/control_work_2/comparsion_in_binary/comparsion_in_binary.c)
target_compile_options(comparsion PRIVATE -Wall -Wextra -pedantic)

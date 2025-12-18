cmake_minimum_required(VERSION 3.25)
project(C_homework C)
add_compile_options(-Wall -Wextra -pedantic)

# Libraries
add_library(stack src/stack_and_queue/stack/stack.c)

# Executables and links with libraries
add_executable(hello_world src/hello_world/hello_world.c)

add_executable(fast_calc_of_polynom src/homework_deadline_25_sep/fast_calculation_of_polynomial/fast_calculation_of_polynomial.c)

add_executable(incomplete_quotient src/homework_deadline_25_sep/incomplete_quotient/incomplete_quotient.c)

add_executable(lucky_tickets src/homework_deadline_25_sep/lucky_tickets/lucky_tickets.c)

add_executable(massive_reroll src/homework_deadline_25_sep/massive_reroll/massive_reroll.c)

add_executable(sorting_station src/stack_and_queue/stack/sorting_station.c)
target_link_libraries(sorting_station PRIVATE stack)

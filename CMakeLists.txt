cmake_minimum_required(VERSION 3.25)

# Hello World
project(hello_world C)

add_executable(hello_world src/hello_world/hello_world.c)
target_compile_options(hello_world PRIVATE -Wall -Wextra -pedantic)

# Fast calculation of polynomial
project(fast_calc_of_polynom C)

add_executable(fast_calc_of_polynom src/homework_deadline_25_sep/fast_calculation_of_polynomial/fast_calculation_of_polynomial.c)
target_compile_options(fast_calc_of_polynom PRIVATE -Wall -Wextra -pedantic)

# Incomplete quotient
project(incomplete_quotient C)

add_executable(incomplete_quotient src/homework_deadline_25_sep/incomplete_quotient/incomplete_quotient.c)
target_compile_options(incomplete_quotient PRIVATE -Wall -Wextra -pedantic)

# Lucky tickets
project(lucky_tickets C)

add_executable(lucky_tickets src/homework_deadline_25_sep/lucky_tickets/lucky_tickets.c)
target_compile_options(lucky_tickets PRIVATE -Wall -Wextra -pedantic)

# Massive reroll
project(massive_reroll C)

add_executable(massive_reroll src/homework_deadline_25_sep/massive_reroll/massive_reroll.c)
target_compile_options(massive_reroll PRIVATE -Wall -Wextra -pedantic)

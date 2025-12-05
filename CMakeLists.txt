cmake_minimum_required(VERSION 3.25)
project(double_under_microscope C)

add_executable(double_under_microscope src/double_under_microscope/double_under_microscope.c)
target_compile_options(double_under_microscope PRIVATE -Wall -Wextra -pedantic)

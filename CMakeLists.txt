cmake_minimum_required(VERSION 3.16)
project(multithreading)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_compile_options(-Wall -Wextra -pedantic -Werror)

add_subdirectory(chapter1)
add_subdirectory(chapter3)
add_subdirectory(chapter4)
add_subdirectory(chapter5)
add_subdirectory(chapter8)
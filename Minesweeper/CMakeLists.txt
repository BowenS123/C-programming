cmake_minimum_required(VERSION 3.16)

project(minesweeper C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

add_executable(minesweeper
    src/main.c
    src/minesweeper.c
)

target_include_directories(minesweeper PRIVATE include)

if (MSVC)
    target_compile_options(minesweeper PRIVATE /W4)
else()
    target_compile_options(minesweeper PRIVATE -Wall -Wextra -Wpedantic)
endif()

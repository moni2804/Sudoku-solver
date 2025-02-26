cmake_minimum_required(VERSION 3.28)
project(sudoku C)

set(CMAKE_C_STANDARD 11)

add_executable(sudoku sudoku.c
        puzzle.c
        square.h
        box.c
        row.c)

cmake_minimum_required(VERSION 3.28)
project(cpp_projects)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_projects
        calculator.cpp
        tictactoe.cpp
        student_management_system.cpp
        snake_game/snake.cpp
        snake_game/Snake.h
        snake_game/main.cpp
        snake_game/score_storage.cpp
)

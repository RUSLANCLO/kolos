cmake_minimum_required(VERSION 3.15)
project(kolos C)

set(CMAKE_C_STANDARD 99)

add_executable(kolos main.c)
target_link_libraries(${PROJECT_NAME} ncurses)
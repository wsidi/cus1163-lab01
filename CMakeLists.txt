cmake_minimum_required(VERSION 3.30)
project(week_01)

set(CMAKE_CXX_STANDARD 20)

add_executable(week_01
        main.c
        "file_operations.c"
        system_commands.c
        file_operations.h
        system_commands.h
        file_operations.c
        main.c
        file_operations.h)

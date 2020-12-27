cmake_minimum_required(VERSION 3.17)
project(transportation C)

set(CMAKE_C_STANDARD 11)

add_executable(transportation main.c
        read_file.c
        search.c
        show_data.c
        show_one_by_one.c
        sort.c
        service_functions.c)
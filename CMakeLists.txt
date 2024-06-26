cmake_minimum_required(VERSION 3.25)
project(Philosophers C)
set(CMAKE_C_STANDARD 99)

add_executable(philo
        src/main.c
        src/utils.c
        src/utils.h
)

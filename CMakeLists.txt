cmake_minimum_required(VERSION 3.27)
project(WVMC_Server C)

set(CMAKE_C_STANDARD 23)

add_executable(WVMC_Server main.c GlobalDefinitions.h)

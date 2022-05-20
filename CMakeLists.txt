cmake_minimum_required(VERSION 3.22)
project(linux_programming C)

set(CMAKE_C_STANDARD 99)

add_executable(linux_programming __thread/main.c)
TARGET_LINK_LIBRARIES(linux_programming pthread)

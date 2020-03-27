cmake_minimum_required(VERSION 2.8)
project(LeetCode CXX)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_POSITION_INDEPENDENT_CODE true)

add_executable(LittleGame LittleGame/little_game.cpp)

add_executable(Hanoi Hanoi/Hanoi.cpp)

add_executable(TriangleRecursion TriangleDP/recursion.cpp)
add_executable(TriangleDP TriangleDP/dp.cpp)
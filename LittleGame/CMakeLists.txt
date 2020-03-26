cmake_minimum_required(VERSION 2.8)
project(LittleGame CXX)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror")
set(CMAKE_POSITION_INDEPENDENT_CODE true)

#add_library(${PROJECT_NAME}_src
#        little_game.cpp
#        )

#target_link_libraries(${PROJECT_NAME}_src)

add_executable(little_game little_game.cpp)
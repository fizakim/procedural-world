cmake_minimum_required(VERSION 3.10)
project(Game)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(game main.cpp Player.cpp)
target_link_libraries(game glfw OpenGL::GL)

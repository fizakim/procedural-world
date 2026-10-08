cmake_minimum_required(VERSION 3.10)
project(Game)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(glfw3 REQUIRED)
find_package(OpenGL REQUIRED)

add_executable(game src/main.cpp src/window/Window.cpp src/player/Player.cpp src/object/Sphere.cpp src/terrain/FlatTerrain.cpp)
target_link_libraries(game glfw OpenGL::GL)

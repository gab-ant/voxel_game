cmake_minimum_required(VERSION 3.10)
project(voxel_game)

set(CMAKE_CXX_STANDARD 17)

find_package(OpenGL REQUIRED)
find_package(glfw3 3.3 REQUIRED)

file(COPY shaders DESTINATION ${CMAKE_BINARY_DIR})
file(COPY textures DESTINATION ${CMAKE_BINARY_DIR})

add_executable(voxel_game
    src/main.cpp
    src/renderer.cpp
    src/image.cpp
    src/image_loader.cpp
    external/glad/glad.c
)

target_include_directories(voxel_game PRIVATE
    external/glad/include
)

target_link_libraries(voxel_game
    glfw
    OpenGL::GL
)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

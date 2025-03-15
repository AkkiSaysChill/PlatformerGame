cmake_minimum_required(VERSION 3.10)
project(Platformer)

set(CMAKE_CXX_STANDARD 17)

# Find Raylib
find_package(raylib REQUIRED)

# Automatically add all .cpp and .h files from src/
file(GLOB SOURCES "src/*.cpp")
file(GLOB HEADERS "src/*.h")

# Manually add main.cpp since it's outside src/
set(SOURCES ${SOURCES} main.cpp)

# Add executable
add_executable(Platformer ${SOURCES} ${HEADERS})

# Include directories
target_include_directories(Platformer PRIVATE src /usr/include)

# Link Raylib, rlImGui, and ImGui
target_link_libraries(Platformer raylib rlImGui imgui dl)


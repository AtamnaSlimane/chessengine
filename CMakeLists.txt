cmake_minimum_required(VERSION 3.16)
project(chessengine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find specific SFML modules (3.x syntax)
find_package(SFML 3 COMPONENTS Graphics Window System Audio REQUIRED)

# Include headers
include_directories(${PROJECT_SOURCE_DIR}/include)

# Collect source files
file(GLOB_RECURSE SRC_FILES src/*.cpp)

# Create executable
add_executable(chessengine ${SRC_FILES})

# Link SFML 3 targets
target_link_libraries(chessengine PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio)

cmake_minimum_required(VERSION 3.1)

project(homework_5)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Include subdirectories
add_subdirectory(core)
add_subdirectory(interface)

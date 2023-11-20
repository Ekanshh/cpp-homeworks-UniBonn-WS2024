cmake_minimum_required(VERSION 3.1)

project(homework_3)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include subdirectories
add_subdirectory(api)
# add_subdirectory(src)

# Create library
add_library(homework_3 INTERFACE)

# Add include directories
target_include_directories(homework_3 INTERFACE 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>  # Use this line if you're installing the library
)

# Link libraries
target_link_libraries(homework_3 INTERFACE html_api)
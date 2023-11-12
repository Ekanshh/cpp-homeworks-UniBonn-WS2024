# Reference: https://github.com/sun1211/cmake_with_add_subdirectory

include_directories(include/)
add_library(gnglib src/gng.cpp)
add_executable(task_1 src/main.cpp)
target_link_libraries(task_1 gnglib)

set_target_properties( task_1
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
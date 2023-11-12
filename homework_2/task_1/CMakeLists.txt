# Reference: https://github.com/sun1211/cmake_with_add_subdirectory

# Set the path to the ClangFormat.cmake script
set(CLANG_FORMAT_SCRIPT_PATH "${CMAKE_SOURCE_DIR}/cmake/ClangFormat.cmake")
set(STATIC_ANALYZER_SCRIPT_PATH "${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake")

# Include the ClangFormat.cmake script
if(EXISTS ${CLANG_FORMAT_SCRIPT_PATH})
    include(${CLANG_FORMAT_SCRIPT_PATH})
else()
    message(WARNING "ClangFormat.cmake not found. clang-format won't be used for formatting.")
endif()

# Include the StaticAnalyzers.cmake script
if(EXISTS ${STATIC_ANALYZER_SCRIPT_PATH})
    include(${STATIC_ANALYZER_SCRIPT_PATH})
else()
    message(WARNING "StaticAnalyzers.cmake not found. clang-tidy and cppcheck won't be used for static analysis.")
endif()

include_directories(include/)
add_executable(task_1 src/gng.cpp)

set_target_properties( task_1
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin"
)
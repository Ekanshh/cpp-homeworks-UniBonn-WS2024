# Reference: https://github.com/sun1211/cmake_with_add_subdirectory
cmake_minimum_required(VERSION 3.1)

project(homework_3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set the path to the ClangFormat.cmake script
set(CLANG_FORMAT_SCRIPT_PATH "${CMAKE_SOURCE_DIR}/cmake/ClangFormat.cmake")
set(STATIC_ANALYZER_SCRIPT_PATH "${CMAKE_SOURCE_DIR}/cmake/StaticAnalyzers.cmake")

# Include the ClangFormat.cmake script
# if(EXISTS ${CLANG_FORMAT_SCRIPT_PATH})
#     include(${CLANG_FORMAT_SCRIPT_PATH})
# else()
#     message(WARNING "ClangFormat.cmake not found. clang-format won't be used for formatting.")
# endif()

# # Include the StaticAnalyzers.cmake script
# if(EXISTS ${STATIC_ANALYZER_SCRIPT_PATH})
#     include(${STATIC_ANALYZER_SCRIPT_PATH})
# else()
#     message(WARNING "StaticAnalyzers.cmake not found. clang-tidy and cppcheck won't be used for static analysis.")
# endif()

# defines targets and sources
add_subdirectory(api)
#add_subdirectory(tests)

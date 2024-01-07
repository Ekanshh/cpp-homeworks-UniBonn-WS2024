add_library(homework_7 INTERFACE)

target_include_directories(homework_7 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../core
)
target_link_libraries(homework_7 INTERFACE mat_serialization convert_dataset kmeans)
add_library(homework_5 INTERFACE)

target_include_directories(homework_5 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../core
)
target_link_libraries(homework_5 INTERFACE mat_serialization convert_dataset)
add_library(homework_9 INTERFACE)

target_include_directories(homework_9 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../core
)
target_link_libraries(homework_9 INTERFACE bow_dictionary histogram)
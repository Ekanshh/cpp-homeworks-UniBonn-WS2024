add_library(homework_6 INTERFACE)

target_include_directories(homework_6 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../core
)
target_link_libraries(homework_6 INTERFACE libimage)
add_library(homework_8 INTERFACE)

target_include_directories(homework_8 INTERFACE 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../core
)
target_link_libraries(homework_8 INTERFACE image)
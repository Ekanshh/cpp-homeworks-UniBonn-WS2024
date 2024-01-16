add_library(
    io_strategies STATIC
    io_strategies.cpp
)
target_include_directories(
    io_strategies PUBLIC
    ${PNG_INCLUDE_DIR}
)
target_link_libraries( 
    io_strategies PUBLIC
    ${PNG_LIBRARY}
)


add_library( 
    image STATIC
    image.cpp
)
target_link_libraries(
    image PUBLIC 
    io_strategies)

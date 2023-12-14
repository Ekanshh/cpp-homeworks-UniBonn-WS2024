add_library(mat_serialization STATIC
    serialize.cpp
)
target_link_libraries(mat_serialization 
    PUBLIC ${OpenCV_LIBS})

target_include_directories(mat_serialization PUBLIC ${OpenCV_INCLUDE_DIRS})

add_library(convert_dataset STATIC
    convert_dataset.cpp
)
target_link_libraries(convert_dataset 
    PUBLIC mat_serialization)

add_library(bow_dictionary STATIC
    bow_dictionary.cpp
)
target_link_libraries(bow_dictionary 
    PUBLIC ${OpenCV_LIBS})

target_include_directories(bow_dictionary PUBLIC ${OpenCV_INCLUDE_DIRS})
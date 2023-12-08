find_package( OpenCV REQUIRED )

MESSAGE(STATUS "Include dirs ${OpenCV_INCLUDE_DIRS}")
MESSAGE(STATUS "LINK LIBRARIES ${OpenCV_LIBS}")

include_directories( ${OpenCV_INCLUDE_DIRS} )

add_library(mat_serialization STATIC
    serialize.cpp
)

link_libraries(mat_serialization ${OpenCV_LIBS})
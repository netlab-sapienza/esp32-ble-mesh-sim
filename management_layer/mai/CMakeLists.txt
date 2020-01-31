project(Mai)

add_library(MaiHandler handler.cpp)
target_include_directories(MaiHandler PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
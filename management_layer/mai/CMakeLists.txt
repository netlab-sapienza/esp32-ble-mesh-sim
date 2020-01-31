project(Mai)

add_library(MaiHandler handler.cpp)
target_include_directories(MaiHandler PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(MaiMessage mai_message.cpp)
target_include_directories(MaiMessage PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

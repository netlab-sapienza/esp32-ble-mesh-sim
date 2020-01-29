cmake_minimum_required(VERSION 3.5)
project(Ml_UI_Api)
#add_subdirectory(lib/graph)
#add_subdirectory(lib/dev_node)

add_library(Ml_UI_Api ui_api.cpp)
target_include_directories(Ml_UI_Api PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(Ml_UI_Api LINK_PUBLIC Ml_Dev_Node Ml_Core)
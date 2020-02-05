cmake_minimum_required(VERSION 3.5)
project(Ml_Core)

add_subdirectory(lib/graph)
add_subdirectory(lib/device_graph)
#add_subdirectory(lib/dev_node)

add_library(Ml_Core core.cpp)
target_include_directories(Ml_Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(Ml_Core LINK_PUBLIC Firmware Master Slave Kernel Ml_Dev_Node)
target_link_libraries(Ml_Core PRIVATE Ml_Device_Graph )
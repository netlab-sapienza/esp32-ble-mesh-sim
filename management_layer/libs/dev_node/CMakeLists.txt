project(Ml_Dev_Node)
message(YPOOOOOO)
add_library(Ml_Dev_Node dev_node.cpp)

target_include_directories(Ml_Dev_Node PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
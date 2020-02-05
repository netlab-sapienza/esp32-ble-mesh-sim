project(Ml_Device_Graph)

add_library(Ml_Device_Graph device_graph.cpp)

target_include_directories(Ml_Device_Graph PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

find_package(Boost REQUIRED COMPONENTS system thread chrono)
target_link_libraries(Ml_Device_Graph LINK_PUBLIC ${Boost_LIBRARIES} Ml_Dev_Node Ml_Graph)
#target_link_libraries(Ml_Device_Graph LINK_PUBLIC Ml_Graph)
project(Ml_Core)

add_subdirectory(lib/graph)

add_library(Ml_Core core.cpp)
target_include_directories(Ml_Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(Ml_Core Ml_Graph)
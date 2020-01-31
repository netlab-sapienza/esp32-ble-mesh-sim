project(Mai)

add_library(MaiHandler handler.cpp)
target_include_directories(MaiHandler PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

add_library(IPCMessage ipc_message.cpp)
target_include_directories(IPCMessage PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
target_link_libraries(MaiHandler IPCMessage)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)


message(STATUS "Project dir: ${PROJECT_SOURCE_DIR}")


add_executable(thread_main thread_routine.cpp)
target_link_libraries(thread_main LINK_PUBLIC Routing Master)



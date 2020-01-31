
# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads)

add_executable(thread_main thread_routine.cpp)
target_link_libraries(thread_main LINK_PUBLIC Firmware Master Slave Kernel
  ${CMAKE_THREAD_LIBS_INIT} Ml_Graph Ml_Core)

add_executable(mai_tester mai_tester.cpp)
target_link_libraries(mai_tester LINK_PUBLIC MaiHandler)
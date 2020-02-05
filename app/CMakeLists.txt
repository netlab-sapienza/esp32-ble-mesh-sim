
# specify the C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Threads)


add_executable(thread_main thread_routine.cpp)
include_directories(${Boost_INCLUDE_DIRS})
target_link_libraries(thread_main LINK_PUBLIC Firmware Master Slave Kernel
  ${CMAKE_THREAD_LIBS_INIT} Ml_UI_Api Ml_Core )


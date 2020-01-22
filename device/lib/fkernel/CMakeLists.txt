# Fake Kernel Cmake file
project(kernel)

add_library(Kernel kernel.c)
target_include_directories(Kernel PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")


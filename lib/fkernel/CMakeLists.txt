# Fake Kernel Cmake file
project(Kernel)

add_library(Kernel kernel.c fcallbacks.c ftasks.c )
target_include_directories(Kernel PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")


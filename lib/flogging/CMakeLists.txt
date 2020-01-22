# Fake Logging Cmake file
project(EspLog)

add_library(EspLog esp_log.c)
target_include_directories(EspLog PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

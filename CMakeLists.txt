cmake_minimum_required(VERSION 3.5)

project(esp32-ble-mesh-sim VERSION 1.0 LANGUAGES C CXX)

set(ESP32_SIMULATION true)
set(CMAKE_CXX_FLAGS "-Wall -Wno-write-strings")


# Add bemesh subdirectories
set(ESP32_LIBS_PATH "${PROJECT_SOURCE_DIR}/device/extern/esp32-ble-mesh/components/bemesh")
add_subdirectory("./device/lib")
add_subdirectory("${ESP32_LIBS_PATH}/common")
add_subdirectory("${ESP32_LIBS_PATH}/mid-tier")
add_subdirectory("${ESP32_LIBS_PATH}/master")
add_subdirectory("${ESP32_LIBS_PATH}/slave")
add_subdirectory("${ESP32_LIBS_PATH}/callbacks")
add_subdirectory("${ESP32_LIBS_PATH}/firmware")

add_subdirectory("./management_layer")
add_subdirectory("./user_interface")
add_subdirectory("./app")


add_subdirectory(user-interface)
add_subdirectory(management-layer)
add_subdirectory(app)



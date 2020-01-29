//
// Created by francesco on 22/01/20.
//

#include <vector>

#ifndef ESP32_BLE_MESH_SIM_UI_API_H
#define ESP32_BLE_MESH_SIM_UI_API_H

#endif //ESP32_BLE_MESH_SIM_UI_API_H


namespace ui_api {
//int for eventual error codes
    int create_environment_randomic(unsigned int num_nodes,unsigned int time_span,std::pair<unsigned int, unsigned int> field_sizes);
    int create_environment_time_position(std::vector<std::tuple<unsigned int,std::pair<unsigned int, unsigned int>>> device_list);

    int add_device(std::pair<unsigned int, unsigned int> coordinates);

    int rmv_device(uint8_t mac_address);

    int update_device_position(uint8_t mac_address, std::pair<unsigned int, unsigned int> coordinates);
}
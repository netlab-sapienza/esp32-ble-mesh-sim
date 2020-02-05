//
// Created by francesco on 22/01/20.
//

#include <iostream>
#include <core.h>
#include "ui_api.h"

namespace ui_api {
//int for eventual error codes

    int create_environment_randomic(unsigned int num_nodes,unsigned int time_span,std::pair<unsigned int, unsigned int> field_sizes){
        std::cout << "UI HW "<< std::endl;

        //ml_core::coreDummy();
        return 0;
    }
    int create_environment_time_position(std::vector<std::tuple<unsigned int,std::pair<unsigned int, unsigned int>>> device_list) {
        return 0;
    }

    int add_device(std::pair<unsigned int, unsigned int> coordinates) {
        return 0;
    }

    int rmv_device(uint8_t mac_address) {
        return 0;
    }

    int update_device_position(uint8_t mac_address, std::pair<unsigned int, unsigned int> coordinates) {
        return 0;
    }

}
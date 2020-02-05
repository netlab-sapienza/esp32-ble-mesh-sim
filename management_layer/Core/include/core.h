//
// Created by francesco on 22/01/20.
//

#ifndef ESP32_BLE_MESH_SIM_CORE_H
#define ESP32_BLE_MESH_SIM_CORE_H

#include <iostream>

namespace ml_core {
    //it should spawn the MAI and manage the communication with it
    //it should initialize the graph and all the management threads
    void initializeCore(); //app (or user_interface) should call it in the beginning




    void coreDummy();
}



#endif //ESP32_BLE_MESH_SIM_CORE_H



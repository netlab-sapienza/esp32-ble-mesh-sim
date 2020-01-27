//
// Created by francesco on 24/01/20.
//

#ifndef ESP32_BLE_MESH_SIM_DEV_NODE_H
#define ESP32_BLE_MESH_SIM_DEV_NODE_H
#include <iostream>



namespace ml_dev_node {
    class Dev_node {


    public:
        Dev_node(int num);
        int numero;

        friend std::ostream &operator<<( std::ostream &output, const Dev_node &Dn );

        //todo
    };

    std::ostream &operator<<( std::ostream &output, const Dev_node &Dn );
}



#endif //ESP32_BLE_MESH_SIM_DEV_NODE_H

//
// Created by francesco on 24/01/20.
//

#ifndef ESP32_BLE_MESH_SIM_DEV_NODE_H
#define ESP32_BLE_MESH_SIM_DEV_NODE_H
#include <iostream>
#include <tuple>



namespace ml_dev_node {
    class Dev_node {
        int node_id;
        std::pair<float, float> position;



    private:
        Dev_node();

    public:
        Dev_node(int id);

        void setPosition(const std::pair<float, float> &position);
        std::pair<float, float> getPosition() const;



        friend std::ostream &operator<<( std::ostream &output, const Dev_node &Dn );

        //todo
    };

    std::ostream &operator<<( std::ostream &output, const Dev_node &Dn );
}



#endif //ESP32_BLE_MESH_SIM_DEV_NODE_H

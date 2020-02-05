//
// Created by francesco on 05/02/20.
//




#include <dev_node.h>

#ifndef ESP32_BLE_MESH_SIM_GRAPH_MANAGER_H
#define ESP32_BLE_MESH_SIM_GRAPH_MANAGER_H

#endif //ESP32_BLE_MESH_SIM_GRAPH_MANAGER_H


namespace ml_connection_graph {


class DeviceGraph{

        static DeviceGraph *network_graph;

        DeviceGraph();

    public:
        //static DeviceGraph *getNetwork_graph();

        void add_client();

        void add_server();

        void turnoff_client();

        void turnoff_server();

        void switch_to_client();

        void switch_to_server();


        void add_connection();

        void remove_connection();
    };


}
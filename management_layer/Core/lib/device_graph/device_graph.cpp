//
// Created by francesco on 05/02/20.
//


#include <dev_node.h>
#include "include/device_graph.hpp"


namespace ml_device_graph {

    DeviceGraph *DeviceGraph::network_graph = 0;

    DeviceGraph::DeviceGraph():Graph(){
        std::cout << "Building Network Graph... \n";
    }

    void DeviceGraph::add_client() {

    }

    void DeviceGraph::add_server() {

    }

    void DeviceGraph::turnoff_client() {

    }

    void DeviceGraph::turnoff_server() {

    }

    void DeviceGraph::switch_to_client() {

    }

    void DeviceGraph::switch_to_server() {

    }

    void DeviceGraph::add_connection() {

    }

    void DeviceGraph::remove_connection() {

    }


}
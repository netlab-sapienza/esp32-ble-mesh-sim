//
// Created by francesco on 22/01/20.
//

#ifndef ESP32_BLE_MESH_SIM_EDGE_H
#define ESP32_BLE_MESH_SIM_EDGE_H


#include <cstdint>
#include <iostream>

namespace ml_graph {
    class Edge {
    public:
        Edge(unsigned int weight);

        unsigned int weight;
        friend std::ostream &operator<<( std::ostream &output, const Edge &Ed );
    };

    std::ostream &operator<<( std::ostream &output, const Edge &Ed );
}

#endif //ESP32_BLE_MESH_SIM_EDGE_H

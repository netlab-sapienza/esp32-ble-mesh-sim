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
        Edge(int8_t* src_id, int8_t* dest_id, unsigned int weight);
        int8_t src;
        int8_t dest;
        unsigned int weight;
        friend std::ostream &operator<<( std::ostream &output, const Edge &Ed );
    };

    std::ostream &operator<<( std::ostream &output, const Edge &Ed );
}

#endif //ESP32_BLE_MESH_SIM_EDGE_H

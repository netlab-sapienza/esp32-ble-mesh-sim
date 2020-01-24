//
// Created by francesco on 22/01/20.
//

#include "edge.h"

namespace ml_graph {

    Edge::Edge(int8_t* src_id, int8_t* dest_id, unsigned int weight_edge) {
        src = *src_id;
        dest = *dest_id;
        weight = weight_edge;
    }

    std::ostream &operator<<( std::ostream &output, const Edge &Ed ) {

        output << " Edge-> source: " << Ed.src << " dest: " << Ed.dest << " weight: "<< Ed.weight << " ";
        return output;

    }



}

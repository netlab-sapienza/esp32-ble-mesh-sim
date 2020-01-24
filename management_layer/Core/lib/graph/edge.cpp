//
// Created by francesco on 22/01/20.
//

#include "edge.h"

namespace ml_graph {

    Edge::Edge(unsigned int weight_edge) {
        weight = weight_edge;
    }

    std::ostream &operator<<( std::ostream &output, const Edge &Ed ) {

        output << " Edge-> weight: "<< Ed.weight << " ";
        return output;

    }



}

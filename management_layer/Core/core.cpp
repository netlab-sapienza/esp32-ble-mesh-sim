//
// Created by francesco on 22/01/20.
//
#include <graph.hpp>
#include <dev_node.h>
#include "core.h"


namespace ml_core {
//int for eventual error codes



    void coreDummy() {
        std::cout << "coreDummy" <<std::endl;

        ml_graph::Graph<int> network_graph;

        ml_dev_node::Dev_node dummy_node(7);

        std::cout << dummy_node.numero <<std::endl;

    }


}


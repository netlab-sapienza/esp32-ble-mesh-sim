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

        ml_graph::Graph<ml_dev_node::Dev_node> network_graph;

        ml_dev_node::Dev_node dummy_node(7);
        ml_dev_node::Dev_node dummy_node2(97);

        std::cout << dummy_node.numero <<std::endl;

        int gig = 5;
        network_graph.add_client(&gig,&dummy_node);

        ml_graph::Edge eggio( 7);

        network_graph.add_edge(new int(12),new int(44),&eggio);

        ml_graph::Edge eggio2( 99);

        network_graph.add_edge(new int(00),new int(11),&eggio2);

        ml_graph::Edge eggio3( 6);

        network_graph.add_edge(new int(00),new int(44),&eggio3);
        network_graph.printGraph();

    }


}


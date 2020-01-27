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


        network_graph.add_client(new int(12),&dummy_node);
        network_graph.add_client(new int(44),&dummy_node);
        network_graph.add_client(new int(00),&dummy_node);
        network_graph.add_client(new int(11),&dummy_node);
        network_graph.add_client(new int(55),&dummy_node);
        std::cout <<"*** 1 grafo vuoto*** "<<std::endl;
        network_graph.printGraph();

        ml_graph::Edge eggio( 7);
        network_graph.add_edge(new int(12),new int(44),&eggio);
        ml_graph::Edge eggio2( 99);
        network_graph.add_edge(new int(00),new int(11),&eggio2);
        ml_graph::Edge eggio3( 6);
        network_graph.add_edge(new int(00),new int(44),&eggio3);
        network_graph.add_edge(new int(55),new int(44),&eggio3);
        network_graph.add_edge(new int(12),new int(55),&eggio3);
        std::cout <<"*** 2 secondo grafo*** "<<std::endl;
        network_graph.printGraph();

       /* network_graph.remove_edge(new int(55),new int(44));
        std::cout <<"***new graph*** "<<std::endl;
        network_graph.printGraph();*/

        network_graph.remove_client_node(new int(0));
        std::cout <<"***new graph*** "<<std::endl;
        network_graph.printGraph();

    }


}


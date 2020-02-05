//
// Created by francesco on 22/01/20.
//


#include "core.h"
#include "dev_node.h"

namespace ml_core {
//int for eventual error codes

    void initializeCore() {

        //1)initialize graph

        //ml_graph::Graph<ml_dev_node::Dev_node> *network_graph = network_graph->getNetwork_graph();

        //2) initialize MAI

        //3)create socket to talk to  MAI
            //3.1)start listening to it

        //4)create socket to talk to UI
            //4.1)start listening to it

        //5) start simulation:send data to create nodes

        //6)for each MAI request spawn a worker thread

    }

    /*void coreDummy() {
        std::cout << "coreDummy" <<std::endl;

        ml_graph::Graph<ml_dev_node::Dev_node> *network_graph = network_graph->getNetwork_graph();

        ml_dev_node::Dev_node dummy_node(7);
        ml_dev_node::Dev_node dummy_node2(97);

        std::cout << "dummynode" << dummy_node <<std::endl;

        int gig = 5;
        network_graph->add_client_node(&gig, &dummy_node);


        network_graph->add_client_node(new int(12), &dummy_node);
        network_graph->add_client_node(new int(44), &dummy_node);
        network_graph->add_client_node(new int(00), &dummy_node);
        network_graph->add_client_node(new int(11), &dummy_node);
        network_graph->add_client_node(new int(55), &dummy_node);
        std::cout <<"*** 1 grafo vuoto*** "<<std::endl;
        network_graph -> printGraph();

        ml_graph::Edge eggio( 7);
        network_graph -> add_edge(new int(12),new int(44),&eggio);
        ml_graph::Edge eggio2( 99);
        network_graph -> add_edge(new int(00),new int(11),&eggio2);
        ml_graph::Edge eggio3( 6);
        network_graph -> add_edge(new int(00),new int(44),&eggio3);
        network_graph -> add_edge(new int(55),new int(44),&eggio3);
        network_graph -> add_edge(new int(12),new int(55),&eggio3);
        std::cout <<"*** 2 secondo grafo*** "<<std::endl;
        network_graph -> printGraph();

       *//* network_graph -> remove_edge(new int(55),new int(44));
        std::cout <<"***new graph*** "<<std::endl;
        network_graph -> printGraph();*//*

        network_graph -> remove_client_node(new int(0));
        std::cout <<"***new graph*** "<<std::endl;
        network_graph -> printGraph();

    }*/


}


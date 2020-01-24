/*
 * graph.hpp
 */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include "edge.h"

namespace ml_graph {

    template<typename T>
    class Graph {
        // element i of edge_vect represent the outgoing edges
        // of i-esim node
        std::map<uint8_t, std::map<uint8_t, Edge>> edge_mat;
        // Each element of data_vect represent one node. Each node is
        // identified from it's index in this vector
        std::unordered_map<uint8_t, T*> server_vect;
        std::unordered_map<uint8_t, T*> client_vect;
        //std::size_t num_nodes;

    public:
        Graph();

        /*
         * add a new node in the graph.
         * Returns:
         *   positive integer representing the ID of the node if succesful
         *   negative integer if an error occurred
         */
        int add_client(uint8_t* node_mac, T *node_data);

        int add_server(uint8_t* node_mac, T *node_data);

        /*
         * add a new edge between two existing nodes
         * Returns:
         *   0 if succesful
         *   -1 otherwise
         */
        int add_edge(uint8_t* t_src, uint8_t *t_dest);

        /*
         * remove the node identified by t_id index in the data_vect
         * and all edges related to him.
         * ISSUE: how do you remove incoming edges ???
         * Returns:
         *   0 if succesful
         *   -1 otherwise
         */
        int remove_client_node(uint8_t* node_mac, T *node_data);

        int remove_server_node(uint8_t* node_mac, T *node_data);

        /*
         * remove the edge going from t_src node to t_dest node.
         * Returns:
         *   0 if succesful
         *   -1 otherwise
         */
        int remove_edge(uint8_t *t_src, uint8_t *t_dest);

        /*
         * Returns the list of available nodes
         */
        std::vector<uint8_t> active_clients(void) const;

        std::vector<uint8_t> active_servers(void) const;

        /*
         * Returns:
         *   0 if t_id exists
         *   -1 otherwise
         */
        std::vector<T *> scan() const;

        //UI side

        std::map<uint8_t, std::map<uint8_t, Edge>> *read_edge_map();

        std::vector<uint8_t, T *> *get_connections(uint8_t node);

        void printGraph();

        // TODO
    };
}


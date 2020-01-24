/*
 * graph.hpp
 */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include "edge.h"



namespace ml_graph {

    template<class T>
    class Graph {
        // element i of edge_vect represent the outgoing edges
        // of i-esim node
        std::map<int, std::map<int, Edge*>> edge_mat;
        // Each element of data_vect represent one node. Each node is
        // identified from it's index in this vector
        std::unordered_map<int, T*> server_vect;
        std::unordered_map<int, T*> client_vect;
        //std::size_t num_nodes;

    public:
        Graph();

        /*
         * add a new node in the graph.
         * Returns:
         *   positive integer representing the ID of the node if succesful
         *   negative integer if an error occurred
         */
        int add_client(int* node_mac, T *node_data);

        int add_server(int* node_mac, T *node_data);

        /*
         * add a new edge between two existing nodes
         * Returns:
         *   0 if succesful
         *   -1 otherwise
         */
        int add_edge(int* t_src, int *t_dest, Edge* Ed);

        /*
         * remove the node identified by t_id index in the data_vect
         * and all edges related to him.
         * ISSUE: how do you remove incoming edges ???
         * Returns:
         *   0 if succesful
         *   -1 otherwise
         */
        int remove_client_node(int* node_mac, T *node_data);

        int remove_server_node(int* node_mac, T *node_data);

        /*
         * remove the edge going from t_src node to t_dest node.
         * Returns:
         *   0 if succesful
         *   -1 otherwise
         */
        int remove_edge(int *t_src, int *t_dest);

        /*
         * Returns the list of available nodes
         */
        std::vector<int> active_clients(void) const;

        std::vector<int> active_servers(void) const;

        /*
         * Returns:
         *   0 if t_id exists
         *   -1 otherwise
         */
        std::vector<T *> scan() const;

        //UI side

        std::map<int, std::map<int, Edge>> *read_edge_map();

        std::vector<int, T *> *get_connections(int node);

        void printGraph();


    };

    //TODO

    template<class T>
    Graph<T>::Graph() {
        std::cout << "Costruisco \n";
    }


    template<class T>
    int Graph<T>::add_client(int* node_mac, T *node_data){
        //todo: eliminare il cout quando riconvertiamo a int8_t
        std::cout << *node_mac <<" " << *node_data <<std::endl;
        client_vect[*node_mac] = node_data;


        /*typename std::unordered_map<int, T*>::iterator iter;

        std::cout << "KEY\tELEMENT" << std::endl;
        for (iter = client_vect.begin(); iter != client_vect.end(); iter++)
        {
            std::cout << iter->first;
            std::cout << '\t' << *(iter->second) << '\n'
                 << std::endl;
        }*/

        return 0;

    }

    template<class T>
    int Graph<T>::add_server(int *node_mac, T *node_data){
        //todo: eliminare il cout quando riconvertiamo a int8_t
        std::cout << *node_mac <<" " << *node_data <<std::endl;
        server_vect[*node_mac] = node_data;
        return 0;
    }

    template<class T>
    int Graph<T>::add_edge(int *t_src, int *t_dest,Edge* Ed) {
        std::map<int, std::map<int, Edge*>>::iterator it1;
        std::map<int, std::map<int, Edge*>>::iterator it2;
        it1 = edge_mat.find(*t_src);
        it2 = edge_mat.find(*t_dest);
        if( it1 != edge_mat.end() && it2 != edge_mat.end()) {
            std::map<int, Edge*>::iterator it_inner1;
            it_inner1 = (it1->second).find(*t_dest);
            std::map<int, Edge*>::iterator it_inner2;
            it_inner2 = (it2->second).find(*t_src);

            if (it_inner1 == (it1->second).end() || it_inner2 == (it2->second).end()){
                (it1->second)[*t_dest] = Ed;
                (it2->second)[*t_src] = Ed;
            }
            else {
                return -1; // there is already an edge between src and dest, or an asymmetry error
            }
        }
        else if  ( it1 == edge_mat.end() && it2 == edge_mat.end()){
            std::map<int, Edge*> temp1;
            temp1[*t_dest] = Ed;
            edge_mat[*t_src] = temp1;

            std::map<int, Edge*> temp2;
            temp2[*t_src] = Ed;
            edge_mat[*t_dest] = temp2;
        }
        else {
            return -1; //asymmetry error
        }

        return 0;
    }

    template<class T>
    int Graph<T>::remove_client_node(int *node_mac, T *node_data) {
        return 0;
    }

    template<class T>
    int Graph<T>::remove_server_node(int *node_mac, T *node_data) {
        return 0;
    }

    template<class T>
    int Graph<T>::remove_edge(int *t_src, int *t_dest){
        return 0;
    }

    template<class T>
    std::vector<int> Graph<T>::active_clients(void) const{
        std::vector<int> temp;
        return  temp;
    }

    template<class T>
    std::vector<int> Graph<T>::active_servers(void) const{
        std::vector<int> temp;
        return  temp;
    }

    template<class T>
    std::vector<T*> Graph<T>::scan() const{
        std::vector<T*> temp;
        return  temp;
    }

    //UI side
    template<class T>
    std::map<int, std::map<int, Edge>>* Graph<T>::read_edge_map() {
        std::map<int, std::map<int, Edge>>* temp;
        return temp;
    }

    template<class T>
    std::vector<int, T *>* Graph<T>::get_connections(int node) {
        std::vector<int, T *>* temp;
        return temp;

    }

    template<class T>
    void Graph<T>::printGraph() {

        std::cout<< "Print graph \n";

        std::map<int, std::map<int, Edge*> >::iterator it;
        std::map<int, Edge*>::iterator it2;
        for (it = edge_mat.begin(); it != edge_mat.end(); ++it) {
            std::cout<< it->first <<": ";
            for (it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                std::cout<<"("<< it2->first << "," << *(it2->second)<<")";
                std::cout<<"   ";
            }
            std::cout<<std::endl;
        }
    }

}


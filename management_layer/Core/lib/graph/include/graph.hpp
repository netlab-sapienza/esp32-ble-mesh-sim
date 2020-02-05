/*
 * graph.hpp
 */
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include "edge.h"

#include <boost/thread.hpp>
#include <boost/chrono.hpp>



namespace ml_graph {


    template<class T>
    class Graph {

        std::map<int, std::map<int, Edge*>> edge_mat;

        std::unordered_map<int, T*> server_vect;
        std::unordered_map<int, T*> client_vect;


        boost::shared_mutex mutex_edge_mat;
        boost::shared_mutex mutex_server_vect;
        boost::shared_mutex mutex_client_vect;


        static Graph *network_graph;
    public:
        Graph();


        /*static Graph *getNetwork_graph() {
            if (!network_graph)
                network_graph = new Graph();
            return network_graph;
        }*/

        int add_client_node(int* node_mac, T *node_data);

        int add_server_node(int* node_mac, T *node_data);

        int remove_client_node(int* node_mac);

        int remove_server_node(int* node_mac);

        int update_client_node(int* node_mac);

        int update_server_node(int* node_mac);


        int add_edge(int* t_src, int *t_dest, Edge* Ed);

        int remove_edge(int *t_src, int *t_dest);


        std::vector<int> active_clients(void) const;

        std::vector<int> active_servers(void) const;


        std::vector<T *> scan() const;

        //UI side

        std::map<int, std::map<int, Edge>> *read_edge_map();

        std::vector<int, T *> *get_connections(int node);

        void printGraph();

    };

    template<class T>
    Graph<T>* Graph<T>::network_graph = 0;


    template<class T>
    Graph<T>::Graph() {
        std::cout << "Building Network Graph... \n";
    }


    template<class T>
    int Graph<T>::add_client_node(int* node_mac, T *node_data){
        //todo: eliminare il cout quando riconvertiamo a int8_t
        std::cout << *node_mac <<" " << *node_data <<std::endl;
        client_vect[*node_mac] = node_data;
        edge_mat[*node_mac];
        return 0;
    }

    template<class T>
    int Graph<T>::add_server_node(int *node_mac, T *node_data){
        //todo: eliminare il cout quando riconvertiamo a int8_t
        std::cout << *node_mac <<" " << *node_data <<std::endl;

        server_vect[*node_mac] = node_data;
        edge_mat[*node_mac];
        return 0;
    }

    template<class T>
    int Graph<T>::remove_client_node(int* node_mac) {

        int del_clients = client_vect.erase(*node_mac);
        if (del_clients != 1) {
            return -1;
        }

        std::map<int, std::map<int, Edge*>>::iterator it1;
        it1 = edge_mat.find(*node_mac);
        if ( it1 != edge_mat.end() ){
            std::map<int, Edge*>::iterator it_inner1;

            for(it_inner1 =  (it1 -> second).begin(); it_inner1 != (it1 -> second).end(); it_inner1++)
            {
                Graph<T>::remove_edge(node_mac, new int(it_inner1->first));
            }
            edge_mat.erase(it1);

        }
        else {
            return -1; //there should always be an entry in  the edge_mat for that node
        }

        return 0;
    }

    template<class T>
    int Graph<T>::remove_server_node(int *node_mac) {
        int del_servers = server_vect.erase(*node_mac);
        if (del_servers != 1) {
            return -1;
        }

        std::map<int, std::map<int, Edge*>>::iterator it1;
        it1 = edge_mat.find(*node_mac);
        if ( it1 != edge_mat.end() ){
            std::map<int, Edge*>::iterator it_inner1;

            for(it_inner1 =  (it1 -> second).begin(); it_inner1 != (it1 -> second).end(); it_inner1++)
            {
                Graph<T>::remove_edge(node_mac, new int(it_inner1->first));
            }
            edge_mat.erase(it1);

        }
        else {
            return -1; //there should always be an entry in  the edge_mat for that node
        }

        return 0;

    }

    template<class T>
    int Graph<T>::update_client_node(int *node_mac) {
        return 0;
    }

    template<class T>
    int Graph<T>::update_server_node(int *node_mac) {
        return 0;
    }

    template<class T>
    int Graph<T>::add_edge(int *t_src, int *t_dest,Edge* Ed) {

        std::map<int, std::map<int, Edge*>>::iterator it1;
        std::map<int, std::map<int, Edge*>>::iterator it2;
        it1 = edge_mat.find(*t_src);
        it2 = edge_mat.find(*t_dest);

        if(it1 != edge_mat.end() && it2 != edge_mat.end()) {
            std::map<int, Edge*>::iterator it_inner1;
            std::map<int, Edge*>::iterator it_inner2;
            it_inner1 = (it1->second).find(*t_dest);
            it_inner2 = (it2->second).find(*t_src);
            if(it_inner1 != (it1->second).end() || it_inner2 != (it2->second).end()){
                //edge already existing or asymmetric error
                return -1;
            }

            (it1->second)[*t_dest] = Ed;
            (it2->second)[*t_src] = Ed;
        }
        else {
            return -1; //nodes don't exist
        }
        return 0;

    }

    template<class T>
    int Graph<T>::remove_edge(int *t_src, int *t_dest){

        std::map<int, std::map<int, Edge*>>::iterator it1;
        std::map<int, std::map<int, Edge*>>::iterator it2;
        it1 = edge_mat.find(*t_src);
        it2 = edge_mat.find(*t_dest);
        if( it1 != edge_mat.end() && it2 != edge_mat.end()) {
            std::map<int, Edge*>::iterator it_inner1;
            it_inner1 = (it1->second).find(*t_dest);
            std::map<int, Edge*>::iterator it_inner2;
            it_inner2 = (it2->second).find(*t_src);

            if (it_inner1 != (it1->second).end() && it_inner2 != (it2->second).end()){
                (it1->second).erase(it_inner1);
                (it2->second).erase(it_inner2);

                return 0;
            }
            else {
                return -1; //non-existing edge or an asymmetry error
            }
        }
        else {
            return -1; //non-existing nodes or asymmetry error
        }
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


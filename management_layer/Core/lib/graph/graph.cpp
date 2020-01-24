//
// Created by francesco on 22/01/20.
//

#include "graph.hpp"



namespace ml_graph {


    template<typename T>
    Graph<T>::Graph() {

    }

    template<typename T>
    int Graph<T>::add_client(uint8_t *node_mac, T *node_data){
        return 0;
    }

    template<typename T>
    int Graph<T>::add_server(uint8_t *node_mac, T *node_data){
        return 0;
    }

    template<typename T>
    int Graph<T>::add_edge(uint8_t *t_src, uint8_t *t_dest) {
        return 0;
    }

    template<typename T>
    int Graph<T>::remove_client_node(uint8_t *node_mac, T *node_data) {
        return 0;
    }

    template<typename T>
    int Graph<T>::remove_server_node(uint8_t *node_mac, T *node_data) {
        return 0;
    }

    template<typename T>
    int Graph<T>::remove_edge(uint8_t *t_src, uint8_t *t_dest){
        return 0;
    }

    template<typename T>
    std::vector<uint8_t> Graph<T>::active_clients(void) const{
        std::vector<uint8_t> temp;
        return  temp;
    }

    template<typename T>
    std::vector<uint8_t> Graph<T>::active_servers(void) const{
        std::vector<uint8_t> temp;
        return  temp;
    }

    template<typename T>
    std::vector<T*> Graph<T>::scan() const{
        std::vector<T*> temp;
        return  temp;
    }

    //UI side
    template<typename T>
    std::map<uint8_t, std::map<uint8_t, Edge>>* Graph<T>::read_edge_map() {
        std::map<uint8_t, std::map<uint8_t, Edge>>* temp;
        return temp;
    }

    template<typename T>
    std::vector<uint8_t, T *>* Graph<T>::get_connections(uint8_t node) {
        std::vector<uint8_t, T *>* temp;
        return temp;

    }

    template<typename T>
    void Graph<T>::printGraph() {

        std::cout<< "Print graph \n";

        std::map<uint8_t, std::map<uint8_t, Edge> >::iterator it;
        std::map<uint8_t, Edge>::iterator it2;
        for (it = edge_mat.begin(); it != edge_mat.end(); ++it) {
            std::cout<< it->first <<": ";
            for (it2 = it->second.begin(); it2 != it->second.end(); ++it2) {
                std::cout<<"("<< it2->first << "," << it2->second<<")";
                std::cout<<"   ";
            }
            std::cout<<std::endl;
        }
    }

}

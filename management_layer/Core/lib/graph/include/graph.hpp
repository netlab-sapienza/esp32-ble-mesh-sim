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

typedef boost::shared_lock<boost::shared_mutex> read_lock_t;
typedef boost::unique_lock<boost::shared_mutex> write_lock_t;

typedef boost::upgrade_lock<boost::shared_mutex> upgrade_lock_t;
typedef boost::upgrade_to_unique_lock<boost::shared_mutex> upgrade_to_unique_lock_t;



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


    protected:
        Graph();
    public:



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

        boost::optional<T*> get_client_node(int* node_mac);
        boost::optional<T*> get_server_node(int* node_mac);


        int add_connection(int* t_src, int *t_dest, Edge* Ed);

        int remove_connection(int *t_src, int *t_dest);



        std::vector<int> active_clients(void) const;

        std::vector<int> active_servers(void) const;


        std::vector<T *> scan() const;

        //UI side

        std::map<int, std::map<int, Edge>> *read_edge_map();

        std::vector<int, T *> *get_connections(int node);

        void printGraph();

    };

    /*template<class T>
    Graph<T>* Graph<T>::network_graph = 0;*/


    template<class T>
    Graph<T>::Graph() {
        std::cout << "Building Generic Graph... \n";
    }


    template<class T>
    int Graph<T>::add_client_node(int* node_mac, T *node_data){
        //todo: eliminare il cout quando riconvertiamo a int8_t
        std::cout << *node_mac <<" " << *node_data <<std::endl;
        write_lock_t lock_cv(mutex_client_vect);
        client_vect[*node_mac] = node_data;
        lock_cv.unlock();
        write_lock_t lock_em(mutex_edge_mat);
        edge_mat[*node_mac];
        return 0;
    }

    template<class T>
    int Graph<T>::add_server_node(int *node_mac, T *node_data){
        //todo: eliminare il cout quando riconvertiamo a int8_t
        std::cout << *node_mac <<" " << *node_data <<std::endl;
        write_lock_t lock_sv(mutex_server_vect);
        server_vect[*node_mac] = node_data;
        lock_sv.unlock();

        write_lock_t lock_em(mutex_edge_mat);
        edge_mat[*node_mac];
        return 0;
    }

    template<class T>
    int Graph<T>::remove_client_node(int* node_mac) {

        write_lock_t lock_cv(mutex_client_vect);
        int del_clients = client_vect.erase(*node_mac);
        if (del_clients != 1) {
            return -1;
        }
        lock_cv.unlock();
        read_lock_t lock_em(mutex_edge_mat);
        std::map<int, std::map<int, Edge*>>::iterator it1;

        it1 = edge_mat.find(*node_mac);
        if ( it1 != edge_mat.end() ){
            std::map<int, Edge*>::iterator it_inner1;

            for(it_inner1 =  (it1 -> second).begin(); it_inner1 != (it1 -> second).end(); it_inner1++)
            {
                Graph<T>::remove_connection(node_mac, new int(it_inner1->first));
            }
            lock_em.unlock();
            write_lock_t lock_em{mutex_edge_mat};

            edge_mat.erase(it1);
            lock_em.unlock();

        }
        else {
            return -1; //there should always be an entry in  the edge_mat for that node
        }

        return 0;
    }

    template<class T>
    int Graph<T>::remove_server_node(int *node_mac) {
        write_lock_t lock_sv(mutex_server_vect);
        int del_servers = server_vect.erase(*node_mac);
        lock_sv.unlock();
        if (del_servers != 1) {
            return -1;
        }

        std::map<int, std::map<int, Edge*>>::iterator it1;
        upgrade_lock_t lock_em(mutex_edge_mat);
        it1 = edge_mat.find(*node_mac);
        if ( it1 != edge_mat.end() ){
            std::map<int, Edge*>::iterator it_inner1;

            for(it_inner1 =  (it1 -> second).begin(); it_inner1 != (it1 -> second).end(); it_inner1++)
            {
                Graph<T>::remove_connection(node_mac, new int(it_inner1->first));
            }
            upgrade_to_unique_lock_t uniqueLock(lock_em);

            edge_mat.erase(it1);
            lock_em.unlock();

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
    int Graph<T>::add_connection(int *t_src, int *t_dest,Edge* Ed) {

        std::map<int, std::map<int, Edge*>>::iterator it1;
        std::map<int, std::map<int, Edge*>>::iterator it2;
        upgrade_lock_t  lock_em(mutex_edge_mat);
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

            upgrade_to_unique_lock_t uniqueLock(lock_em);

            (it1->second)[*t_dest] = Ed;
            (it2->second)[*t_src] = Ed;
        }
        else {
            return -1; //nodes don't exist
        }
        return 0;

    }

    template<class T>
    int Graph<T>::remove_connection(int *t_src, int *t_dest){

        std::map<int, std::map<int, Edge*>>::iterator it1;
        std::map<int, std::map<int, Edge*>>::iterator it2;
        upgrade_lock_t  lock_em{mutex_edge_mat};
        it1 = edge_mat.find(*t_src);
        it2 = edge_mat.find(*t_dest);
        if( it1 != edge_mat.end() && it2 != edge_mat.end()) {
            std::map<int, Edge*>::iterator it_inner1;
            it_inner1 = (it1->second).find(*t_dest);
            std::map<int, Edge*>::iterator it_inner2;
            it_inner2 = (it2->second).find(*t_src);

            if (it_inner1 != (it1->second).end() && it_inner2 != (it2->second).end()){
                upgrade_to_unique_lock_t uniqueLock(lock_em);

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
    boost::optional<T*> Graph<T>::get_client_node(int *node_mac) {

        read_lock_t lock_cv(mutex_client_vect);


        typename std::unordered_map<int, T*>::iterator it1;
        it1 = client_vect.find(*node_mac);
        if( it1 != client_vect.end()){
            std::cout<<"LAMADONNA "<< *(it1->second) <<std::endl;
            return (it1->second);
        }
        else
            return boost::optional<T*>{};

    }

    template<class T>
    boost::optional<T*> Graph<T>::get_server_node(int *node_mac) {


       read_lock_t lock_sv(mutex_server_vect);
        typename std::unordered_map<int, T*>::iterator it1;
        it1 = server_vect.find(*node_mac);
        if( it1 != server_vect.end()){
            std::cout<<"get_server_node retrieved value: "<< *(it1->second) <<std::endl;
            return it1->second;
        }
        else {
            return boost::optional<T*>{};
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

        read_lock_t lock_em(mutex_edge_mat);

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
        lock_em.unlock();
    }




}


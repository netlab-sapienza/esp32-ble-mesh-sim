//
// Created by francesco on 05/02/20.
//


#include <dev_node.h>
#include "include/device_graph.hpp"
#include <boost/optional/optional_io.hpp>


namespace ml_device_graph {

    DeviceGraph *DeviceGraph::network_graph = nullptr;

    DeviceGraph::DeviceGraph():Graph(){
        std::cout << "Building Network Graph... \n";
    }

    int DeviceGraph::switch_to_client(int *node_mac){

        boost::optional<ml_dev_node::Dev_node*>  res = get_server_node(node_mac);
        if(res){
            ml_dev_node::Dev_node* dev = res.get();
            int success = remove_server_node(node_mac);
            if(success) {
                success = add_client_node(node_mac,dev);
                if(success) {
                    return 0;
                }
                else {
                    return -1; //no server found
                }
            }
            else {
                return -1; //no server found
            }


            //std::cout <<"***olone*** "<< *dev <<std::endl;

        }
        else {
            return -1; //no server found
        }
        //ml_dev_node::Dev_node* dev = get_client_node(node_mac);

        //std::cout <<"***olone*** "<< *dev <<std::endl;



        return 0;
    }

    int DeviceGraph::switch_to_server(int *node_mac) {
        return 0;
    }

}
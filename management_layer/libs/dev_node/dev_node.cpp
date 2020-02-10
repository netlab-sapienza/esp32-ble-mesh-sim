//
// Created by francesco on 24/01/20.
//

#include "dev_node.h"
namespace ml_dev_node {

    Dev_node::Dev_node() {
        position.first = 0;
        position.second = 0;
    }

    Dev_node::Dev_node(int id):Dev_node() {
        node_id = id;
    }

    std::ostream &operator<<( std::ostream &output, const Dev_node &Dn ) {

        output << " Dev_node-> id: " << Dn.node_id << " Position: (" << Dn.position.first<<";"<<Dn.position.second<<")";
        return output;

    }

    std::pair<float, float> Dev_node::getPosition() const {
        return position;
    }

    void Dev_node::setPosition(const std::pair<float, float> &position) {
        Dev_node::position = position;
    }


}


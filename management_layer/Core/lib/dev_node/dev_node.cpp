//
// Created by francesco on 24/01/20.
//

#include "dev_node.h"
namespace ml_dev_node {

    Dev_node::Dev_node(int num) {
        numero = num;
    }

    std::ostream &operator<<( std::ostream &output, const Dev_node &Dn ) {

        output << " Dev_node-> numero: " << Dn.numero << " ";
        return output;

    }


}


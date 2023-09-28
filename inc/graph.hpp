
#ifndef YAPP_GRAPH_H
#define YAPP_GRAPH_H

#include <vector>
#include "display.hpp"
#include "node.hpp"

namespace YAPP {



    /*
    The graph class stores all the nodes and defines the relationship 
    between them. 
    */
    class Graph {

        unsigned int nodeCount;
        float resolution;
        NodeGeometry nodeType; 
        //std::vector<>

        Graph(NodeGeometry nodeType);

        ~Graph();

        void loadMap(YAPP::defaultMap map);
    };
}

#endif // YAPP_GRAPH_H

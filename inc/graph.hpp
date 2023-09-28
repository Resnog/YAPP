
#ifndef YAPP_GRAPH_H
#define YAPP_GRAPH_H

#include <vector>
#include "display.hpp"

namespace YAPP {

enum GraphGeometry {
    Square,
    Hexagon,
};

    /*
    The graph class stores all the nodes and defines the relationship 
    between them. 
    */
    class Graph {

        unsigned int nodeCount;
        GraphGeometry geometryType; 
        //std::vector<>

        Graph(GraphGeometry geometryType);

        ~Graph();

        void loadMap(YAPP::defaultMap map);
    }
}

#endif // YAPP_GRAPH_H

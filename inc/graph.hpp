
#ifndef YAPP_GRAPH_H
#define YAPP_GRAPH_H

#include <vector>
#include "map.hpp"
#include "node.hpp"

namespace YAPP {



    /*
    The graph class stores all the nodes and defines the relationship 
    between them. It is supposed to be used by any algorithm to calculate
    a Path Planning solution for a given map, considering if that map has 
    or has not a solution to that particular problem.
    */
    class Graph {
        public:
            unsigned int nodeCount;

            NodeGeometry nodeType;
            // The nodeMap is equal to a loaded map
            std::vector<std::vector<Node>> nodeMap; 

            Graph(NodeGeometry nodeType, YAPP::Map map);

            ~Graph();

        private:
            void getNodeNeighbours(Node);

    };
}

#endif // YAPP_GRAPH_H

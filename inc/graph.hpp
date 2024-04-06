
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
            NodeGeometry nodeType;
            std::vector<Node> nodes;
            std::vector<std::vector<size_t>> nodeIdMap; 
            YAPP::Map *map;
            Graph(NodeGeometry nodeType, YAPP::Map *map);

            ~Graph();

            size_t getNodeId(size_t row, size_t col);

        private:
            void getNodeNeighbours(Node* n);
            void getVonNeumannNeighbours(Node* n);

    };
}

#endif // YAPP_GRAPH_H


#ifndef YAPP_NODE_H
#define YAPP_NODE_H

#include <vector>

namespace YAPP {

    enum NodeGeometry {
        Square = (size_t) 4,
        Hexagon = (size_t) 6,
    };

    enum NodeDistance {
        Manhattan,
        Euclid,
    };

    /*
    The node is the main element that defines the state of a geometrically
    defined area within a map.

    Nodes objects are created by Graph objects in order to define the geometrical
    relationship between them, store them and facilitate the map for a search 
    algorithm to work in.
    */
    class Node {
        
        public:
            unsigned int id;
            float positionX; 
            float positionY;
            Node** neighbours;
            bool visitedStatus;

            Node(unsigned int newId, float x, float y);
            ~Node();

            void distance(Node a, Node b, NodeDistance distanceType);
            void printNodeInfo();
            
        private:

            float distanceManhattan();
            float distanceEuclid();
    };
}

#endif // YAPP_NODE_H

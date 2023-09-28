
#ifndef YAPP_NODE_H
#define YAPP_NODE_H

#include <vector>

namespace YAPP {

    enum NodeGeometry {
        Square,
        Hexagon,
    };

    enum NodeDistance {
        Manhattan,
        Euclid,
    };

    /*
    The node is the main element that defines the state of a geometrically
    defined area within a map. 
    */
    class Node {
        
        public:
            unsigned int id;
            float positionX; 
            float positionY;
            Node* neighbours;

            Node(unsigned int id, float position_x, float position_y);
            ~Node();

            void distance(Node a, Node b, NodeDistance distanceType);
        private:

        float distanceManhattan();
        float distanceEuclid();
    };
}

#endif // YAPP_NODE_H

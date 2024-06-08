
#ifndef YAPP_NODE_H
#define YAPP_NODE_H

#include <vector>

namespace YAPP {

    enum NodeGeometry {
        VonNeumann = (size_t) 4,
        Hexagon = (size_t) 6,
        Squared = (size_t) 8,
    };

    enum NodeDistance {
        Manhattan,
        Euclid,
    };

    enum NodeSelection{
        CLKWISE,
        CTRCLKWISE,
        RANDOM,
        CUSTOM,
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
            size_t id;
            float positionX; 
            float positionY;
            std::vector<size_t> neighbours;
            

            Node(size_t newId, float x, float y, NodeGeometry nodeType);
            ~Node();

            void distance(Node n,NodeDistance distanceType);
            void printNodeInfo();
            void setAsObstacle();
            bool isAnObstacle();
            void setAsVisited();
            bool hasBeenVisited();
            
        private:
            bool visitedStatus;
            bool isObstacle;
            float distanceManhattan();
            float distanceEuclid();
    };
}

#endif // YAPP_NODE_H

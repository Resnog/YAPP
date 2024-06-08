#include <vector>
#include <iostream>
#include "node.hpp"

YAPP::Node::Node(   size_t newId,
                    float x,
                    float y,
                    NodeGeometry nodeType) {
    positionX = x;
    positionY = y;
    id = newId;
    visitedStatus = false;
    isObstacle = false;
    neighbours.reserve((size_t) nodeType);
}

YAPP::Node::~Node() {}

void YAPP::Node::printNodeInfo() {
    std::cout << " Node     : " << id << std::endl
              << " Row      : " << positionX << std::endl
              << " Col      : " << positionY << std::endl
              << " Obstacle : " << isObstacle << std::endl
              << " Neighs   : " << neighbours.size() << std::endl;
              
    for( size_t id : neighbours){
        std::cout << "   Neighbour with: " << id << std::endl;
    }
}

void YAPP::Node::setAsObstacle() {
    isObstacle = true;
}

bool YAPP::Node::isAnObstacle() {
    return isObstacle;
}


void YAPP::Node::setAsVisited() {
    visitedStatus = false;
}

bool YAPP::Node::hasBeenVisited() {
    return visitedStatus;
}
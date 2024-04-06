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
    isObstacle = false;
    neighbours.reserve((size_t) nodeType);
}

YAPP::Node::~Node() {}

void YAPP::Node::printNodeInfo() {
    std::cout << " Node     : " << id << std::endl
              << " Row      : " << positionX << std::endl
              << " Col      : " << positionY << std::endl
              << " Obstacle : " << isObstacle << std::endl;
    
}

void YAPP::Node::setAsObstacle() {
    isObstacle = true;
}

bool YAPP::Node::isAnObstacle() {
    return isObstacle;
}
#include <vector>
#include <iostream>
#include "node.hpp"

YAPP::Node::Node(   unsigned int newId,
                    float x,
                    float y) {
    positionX = x;
    positionY = y;
    id = newId;
}

YAPP::Node::~Node() {}

void YAPP::Node::printNodeInfo() {
    std::cout << "Node :" << id 
              << " Row: " << positionX
              << " Col: " << positionY << std::endl;
}
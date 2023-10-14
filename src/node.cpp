#include <vector>
#include "node.hpp"

YAPP::Node::Node(   unsigned int newId,
                    float x,
                    float y) {
    positionX = x;
    positionY = y;
    id = newId;
}

YAPP::Node::~Node() {}
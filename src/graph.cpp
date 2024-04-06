#include <vector>
#include "graph.hpp"

YAPP::Graph::Graph(NodeGeometry geometryType, YAPP::Map *map) {

    this->map = map;
    nodeType = geometryType;
    int id = 0;
    std::pair<int, int> mapDimensions = map->getMapSize();

    // Load map into graph
    // Loop over rows
    for(int i = 0; i < mapDimensions.first; i++) {
        std::vector<Node> n;
        nodeMap.push_back(n);

        //Loop over columns
        for (int j = 0; j < mapDimensions.second; j++)
        {
            Node n = Node(id, i, j, nodeType);
            //getNodeNeighbours(&n);
            if(map->map.at(i).at(j) == 1) {
                n.setAsObstacle();
            }
            nodeMap[i].push_back(n);
            id++;
        }
        
    }
}

YAPP::Graph::~Graph(){}

void YAPP::Graph::getNodeNeighbours(Node* n) {
    
    if(this->nodeType == NodeGeometry::VonNeumann) {
        getVonNeumannNeighbours(n);
    }
}

void YAPP::Graph::getVonNeumannNeighbours(Node* n) {
    // Up 
    if(map->map.at(n->positionY-1).at(n->positionX)) {
        n->neighbours[0] = &nodeMap[n->positionY-1][n->positionX];
    }
    // Right
    if(map->map.at(n->positionY).at(n->positionX+1)) {
        n->neighbours[1] = &nodeMap[n->positionY][n->positionX+1];
    }
    // Down
    if(map->map.at(n->positionY+1).at(n->positionX)) {
        n->neighbours[2] = &nodeMap[n->positionY+1][n->positionX];
    }
    // Left
    if(map->map.at(n->positionY).at(n->positionX-1)) {
        n->neighbours[3] = &nodeMap[n->positionY][n->positionX-1];
    }
}
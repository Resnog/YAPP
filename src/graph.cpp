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
        std::vector<size_t> nodeIdMapRow;
        nodeIdMap.push_back(nodeIdMapRow);

        //Loop over columns
        for (int j = 0; j < mapDimensions.second; j++)
        {
            Node n = Node(id, i, j, nodeType);
            if(map->map.at(i).at(j) == 1) {
                n.setAsObstacle();
            }
            nodes.push_back(n);
            nodeIdMap[i].push_back(n.id);
            id++;
        }
        
        // Get all the nodes neighbours
    }
}

YAPP::Graph::~Graph(){}


size_t YAPP::Graph::getNodeId(size_t row, size_t col) {
    return this->nodeIdMap.at(row).at(col);
}

void YAPP::Graph::getNodeNeighbours(Node* n) {
    
    if(this->nodeType == NodeGeometry::VonNeumann) {
        getVonNeumannNeighbours(n);
    }
}

void YAPP::Graph::getVonNeumannNeighbours(Node* n) {
    // Up 
    if(map->map.at(n->positionY-1).at(n->positionX)) {
        n->neighbours.push_back(nodeIdMap[n->positionY-1][n->positionX]);
    }
    // Right
    if(map->map.at(n->positionY).at(n->positionX+1) ) {
        n->neighbours.push_back(nodeIdMap[n->positionY][n->positionX+1]);
    }
    // Down
    if(map->map.at(n->positionY+1).at(n->positionX)) {
        n->neighbours.push_back(nodeIdMap[n->positionY+1][n->positionX]);
    }
    // Left
    if(map->map.at(n->positionY).at(n->positionX-1)) {
        n->neighbours.push_back(nodeIdMap[n->positionY][n->positionX-1]);
    }
}
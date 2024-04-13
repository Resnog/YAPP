#include <iostream>
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
    }
    getAllNodesNeighbours();
}

YAPP::Graph::~Graph(){}


size_t YAPP::Graph::getNodeId(size_t row, size_t col) {
    return this->nodeIdMap.at(row).at(col);
}

void YAPP::Graph::getAllNodesNeighbours() {
    for(size_t i = 0; i < nodes.size(); i++)    {
        if(this->nodeType == NodeGeometry::VonNeumann) {
            Node& aNode = nodes.at(i);
            if(aNode.isAnObstacle()) {
                continue;
            }
            getVonNeumannNeighbours(aNode);
        }
    }
}

void YAPP::Graph::getVonNeumannNeighbours(Node& n) {

    // Get valid neighbours
    std::vector<std::pair<size_t, size_t>> possibleNeighbours = {
        std::make_pair(n.positionY - 1, n.positionX), //Up
        std::make_pair(n.positionY, n.positionX + 1), //Right
        std::make_pair(n.positionY + 1, n.positionX), //Down
        std::make_pair(n.positionY, n.positionX - 1), //Left
    };

    // Check if the coordinates are valid and add to the neighbours
    for(size_t i = 0; i < nodeType; i++) {
        if(possibleNeighbours[i].first < 0
           || possibleNeighbours[i].first >= map->cols )  {
                continue;
           }
        if(possibleNeighbours[i].second < 0
           || possibleNeighbours[i].second >= map->rows) {
                continue;
           }
        size_t neighbourNode = nodeIdMap.at(possibleNeighbours[i].second)
                                        .at(possibleNeighbours[i].first);
        
        if(nodes.at(neighbourNode).isAnObstacle()){
            continue;
        }

        n.neighbours.push_back(
            neighbourNode
        );
    }
}
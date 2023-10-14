#include <vector>
#include "graph.hpp"

YAPP::Graph::Graph(NodeGeometry geometryType, YAPP::Map map) {

    nodeType = geometryType;
    int id = 0;
    std::pair<int, int> mapDimensions = map.getMapSize();

    // Load map into graph
    // Loop over rows
    for(int i = 0; i < mapDimensions.first; i++) {
        std::vector<Node> n;
        nodeMap.push_back(n);

        //Loop over columns
        for (int j = 0; j < mapDimensions.second; j++)
        {
            nodeMap[i].push_back(Node(id, i, j));
            id++;
        }
        
    }
}
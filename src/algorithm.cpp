#include <vector>
#include <queue>
#include "yapp.hpp"
#include "algorithm.hpp"
#include "node.hpp"
#include "graph.hpp"

YAPP::BFS::BFS(Graph* graph, Node* start, Node* goal)
{
    searchGraph = graph;
    status = ALGO_IDLE;
    nodeSelectionMetric = NodeSelection::CLKWISE;
    setStart(start);
    setGoal(goal);
}

void YAPP::Algo::setStart(Node* n)
{
    this->start = n;
}

void YAPP::Algo::setGoal(Node* n)
{
    this->goal = n;
}


YAPP::AlgoStatus YAPP::BFS::solve()
{
    // Put start node into the queue
    // While the FIFO queue is not empty
        // Get from FIFO queue
        // Check if the nodeId is the same as the goal node
            // If so break the loop 
        // Pick neighbour which is alive or unvisited
        // If unvisited set state to Alive and add to the FIFO queue
        // Set the node taken from the FIFO queue to dead as all its 
        // If all neighbours have been visited and their status is now known
        // set status as Dead
}
#ifndef ALGO_H
#define ALGO_H

#include <vector>
#include "yapp.hpp"
#include "graph.hpp"
#include "node.hpp"
#include <queue>

namespace YAPP{

    enum AlgoStatus {
        ALGO_IDLE,
        ALGO_SOLVING,
        ALGO_SOLVED,
        ALGO_NO_SOLUTION_FOUND,
        ALGO_ERR,
    };

    enum AlgoHeuristic {
        ALGO_HEU_SHORTEST_PATH,
        ALGO_HEU_EUCLIDIAN_DISTANCE,
        ALGO_HEU_MANHATTAN_DISTANCE,
        ALGO_HEU_ERR,
    };

    class Algo{
        public:
            // The graph that will be used for the path planning search
            Graph* searchGraph;
            // The nodes that compromise the calculated solution based
            // on the start and the goal on the graph
            std::vector<Node*> solution;
            AlgoStatus status;

            //Algo(){};
            //~Algo(){};

            AlgoStatus virtual solve(){return ALGO_ERR;};
            void setStart(Node *s);
            void setGoal(Node* g);
            

        private:
            AlgoStatus step();
            Node* start;
            Node* goal;
    };
    /***********
     *  Breadth First Search
     * ************/
    
    class BFS :  Algo
    {
        
        private:
            /* data */
            std::queue<Node*> visitedNodes;
            NodeSelection nodeSelectionMetric;
            size_t selectNode(Node *n);
        public:

            YAPP::YAPP_ERR setSelectionType(NodeSelection selectionType);
            YAPP::YAPP_ERR addToQueue(Node* n);
            BFS(Graph* graph, Node* start, Node* goal);
            ~BFS();

            AlgoStatus solve();
    };
}

#endif // ALGO_DISPLAY_H
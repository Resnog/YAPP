
#ifndef YAPP_DISPLAY_H
#define YAPP_DISPLAY_H

#include <array>
#include <SFML/Graphics.hpp>
#include "yapp.hpp"
#include "node.hpp"

namespace YAPP {
    #define defaultMapRows (60/2)
    #define defaultMapColumns (80/2)

    #define defaultMapGridThickness (0.5)

    class NodeDisplay{
        public:
            sf::RectangleShape nodeShape;
            sf::CircleShape nodeCenter;
            sf::RectangleShape nodeNeighbourUpLink;
            sf::RectangleShape nodeNeighbourRightLink;
            sf::RectangleShape nodeNeighbourDownLink;
            sf::RectangleShape nodeNeighbourLeftLink;

            NodeDisplay(size_t colPixels, size_t rowPixels);

            void setNodeShape(sf::RectangleShape &nodeShape);
            void setNodeCenter(float radius, float offsetX, float offsetY);
            void setNodeNeighbourUpLink();
            void setNodeNeighbourRightLink();
            void setNodeNeighbourDownLink();
            void setNodeNeighbourLeftLink();

    };

    class Map {

        public:
            unsigned int rows;
            unsigned int cols;
            unsigned int rowPixels;
            unsigned int colsPixels;
            sf::RenderWindow *window;
            std::vector<std::vector<int>> map;

            std::pair<int,int> getMapSize();
            void printMap();
        
            bool isRowValid(size_t r);
            bool isColValid(size_t c);
    };

    /*
    The defaultMap class generates a map with the default options to run algorithms,
    this is the main class to test YAPP-SFML functionalities. The map consists on a 
    grid of N rows and M colums, the YAPP window currently has a hardcoded resolution
    of 800x600, to simplify the exercise.
    */
    class SquaredMap : public Map {

        public:
    
            std::vector<NodeDisplay> *nodeShapes;
            unsigned int nodeCenterRadius;

            SquaredMap(sf::RenderWindow* aWindow);
            ~SquaredMap();

            void loadDefault();
            void draw();
            void drawItem(sf::Shape &item);

            YAPP_ERR changeSquareColor(unsigned int x, unsigned int y,
                                    sf::Color color);
            
         private:

         void loadDefaultMap();
         void loadRenderMap();
    };

}



#endif // YAPP_DISPLAY_H

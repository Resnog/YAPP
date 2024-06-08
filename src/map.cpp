#include <SFML/Graphics.hpp>
#include <iostream>
#include "map.hpp"
//#include "yapp.cpp"

std::pair<int,int> YAPP::Map::getMapSize() {
        return std::pair<int, int>(rows, cols);
}

YAPP::SquaredMap::SquaredMap(sf::RenderWindow* aWindow) {

        nodeShapes = new std::vector<NodeDisplay>();
        window = aWindow;
        std::cout << "SquaredMap initialized..." << std::endl;
    }

YAPP::SquaredMap::~SquaredMap() {

        delete nodeShapes;
        std::cout << "SquaredMap deleted..." << std::endl;
    }

void YAPP::SquaredMap::loadDefault() {

        rows = defaultMapRows;
        cols = defaultMapColumns;
        
        sf::Vector2u size = window->getSize();
        rowPixels = size.y / rows;
        colsPixels  = size.x / cols;
        nodeCenterRadius = rowPixels / 4;
        
        std::cout << "Row number      : " << rows << std::endl;
        std::cout << "Col number      : " << cols << std::endl;
        std::cout << "Pixels per Row  : " << rowPixels << std::endl;
        std::cout << "Pixels per Col  : " << colsPixels << std::endl;
        
        loadDefaultMap();
        loadRenderMap();
    }

/*
Draw the map on the main rendering window, this window is defined in the 
initialization of the map. This will draw to the window all the rectangles, 
which is ineficient and the user will feel the performance drop when using
YAPP-SFML, this is not desired to update the states in the map.
*/
void YAPP::SquaredMap::draw() {
        for(auto a : *nodeShapes) {
                window->draw(a.nodeShape);
                // TODO: Draw the nodeCenter only if the node is occupied
                //window->draw(a.nodeCenter);
        }
}
// TODO
// Draw the borders in a different color
void YAPP::SquaredMap::loadDefaultMap() {
        // Load default map
        for (size_t i = 0; i < rows; i++)
        {
                std::vector<int> row;
                map.push_back(row);
                for (size_t j = 0; j < cols; j++){
                        if(i == 0 
                           || i == rows - 1
                           || j == 0
                           || j == cols - 1){
                                map[i].push_back(1);
                        }else {
                                map[i].push_back(0);
                        }
                }
        }
        std::cout << "Map rows: " << map.size() << std::endl;
        std::cout << "Map cols: " << map[0].size() << std::endl;
}
void YAPP::SquaredMap::loadRenderMap() {
        NodeDisplay node(colsPixels, rowPixels);

        for(int i = 0; i < rows; i++) {
                sf::Color grey = sf::Color(125,125,135,255);
                for (int j = 0; j < cols; j++)
                {
                        node.nodeShape.setPosition(sf::Vector2f(j * colsPixels,
                                                        i * rowPixels));                        
                        if(map[i][j] == 1){
                                node.nodeShape.setFillColor(grey);
                                node.setNodeCenter(nodeCenterRadius,
                                                   colsPixels,
                                                   rowPixels);
                        }else { 
                                node.nodeShape.setFillColor(sf::Color::White);                        node.setNodeCenter(this->nodeCenterRadius,
                                           this->colsPixels/4,
                                           this->rowPixels/4);
                        }

                        nodeShapes->push_back(node);
                }
        }
        std::cout << "Number of shapes :" << nodeShapes->size() << std::endl;
}

YAPP::YAPP_ERR YAPP::SquaredMap::changeSquareColor( unsigned int x, 
                                                    unsigned int y,
                                                    sf::Color color) {
        if( isRowValid(y) && isColValid(x)) {
                std::cout << "Item number: "<< (rows-1)*x + (cols-1)*y << std::endl;
                nodeShapes->at( cols*y +x ).nodeShape.setFillColor(color);
                return YAPP_OK;
        } else {
                return YAPP_INPUT_VALUE_ERR;
        }
}

bool inline YAPP::Map::isRowValid(size_t r){
        return (r >= 0 && r < this->rows);
}
bool inline YAPP::Map::isColValid(size_t c){
        return (c >= 0 && c < this->cols);
}


void YAPP::Map::printMap() {
        for (size_t i = 0; i < rows; i++)
        {
                std::cout << std::endl;
                for (size_t j = 0; j < cols; j++)
                {
                        std::cout << map[i][j] << std::ends;
                }
        }
        
}

void YAPP::SquaredMap::drawItem(sf::Shape &item){
        this->window->draw(item);
}

void YAPP::NodeDisplay::setNodeShape(sf::RectangleShape &shape) {
        nodeShape = shape;

}

YAPP::NodeDisplay::NodeDisplay(size_t colPixels, size_t rowPixels){
        nodeShape = sf::RectangleShape(sf::Vector2f(colPixels, rowPixels));
        nodeShape.setOutlineColor(sf::Color::Black);
        nodeShape.setOutlineThickness(defaultMapGridThickness);
        nodeShape.setFillColor(sf::Color::White);
        nodeShape.setSize(sf::Vector2f(rowPixels, colPixels));
}

void YAPP::NodeDisplay::setNodeCenter(float radius,
                                      float offsetX,
                                      float offsetY) {
        nodeCenter.setRadius(radius);
        nodeCenter.setFillColor(sf::Color::Yellow);
        nodeCenter.setOutlineColor(sf::Color::Black);
        nodeCenter.setOutlineThickness(defaultMapGridThickness*2);
        sf::Vector2f pos = nodeShape.getPosition();
        pos.x += offsetX;
        pos.y += offsetY;
        nodeCenter.setPosition(pos);
}
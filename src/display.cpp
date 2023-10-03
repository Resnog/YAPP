#include <SFML/Graphics.hpp>
#include <iostream>
#include "display.hpp"
//#include "yapp.cpp"

YAPP::SquaredMap::SquaredMap(sf::RenderWindow* aWindow) {

        shapeMap = new std::vector<sf::RectangleShape>();
        window = aWindow;
        std::cout << "SquaredMap initialized..." << std::endl;
    }

YAPP::SquaredMap::~SquaredMap() {

        delete shapeMap;
        std::cout << "SquaredMap deleted..." << std::endl;
    }

void YAPP::SquaredMap::loadDefault() {

        rows = defaultMapRows;
        cols = defaultMapColumns;
        
        sf::Vector2u size = window->getSize();
        rowPixels = size.y / rows;
        colsPixels  = size.x / cols;
        
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
        for(auto a : *shapeMap) {
                window->draw(a);
        }
}

void YAPP::SquaredMap::loadDefaultMap() {
        // Load default map
        for (size_t i = 0; i < rows; i++)
        {
                std::vector<int> row;
                map.push_back(row);
                for (size_t j = 0; j < cols; j++){
                        map[i].push_back(1);
                        }
                }
        std::cout << "Map rows: " << map.size() << std::endl;
        std::cout << "Map cols: " << map[0].size() << std::endl;
}
void YAPP::SquaredMap::loadRenderMap() {

        sf::RectangleShape rect(sf::Vector2f(colsPixels, rowPixels));
        rect.setOutlineColor(sf::Color::Black);
        rect.setOutlineThickness(defaultMapGridThickness);
        rect.setFillColor(sf::Color::White);
        rect.setSize(sf::Vector2f(rowPixels, colsPixels));

        for(int i = 0; i < rows; i++) {
                
                for (int j = 0; j < cols; j++)
                {
                        if(map[i][j] == 1){
                        rect.setPosition(sf::Vector2f(j * colsPixels,
                                                        i * rowPixels));

                        shapeMap->push_back(rect);
                        window->draw(rect);
                        }
                }
        }
        std::cout << "Number of shapes :" << shapeMap->size() << std::endl;
}

YAPP::YAPP_ERR YAPP::SquaredMap::changeSquareColor( unsigned int x, 
                                                    unsigned int y,
                                                    sf::Color color) {
        if( x >= 0 && y >= 0) {
                std::cout << "Item number: "<< (rows-1)*x + (cols-1)*y << std::endl;
                shapeMap->at( cols*y +x ).setFillColor(color);
                return YAPP_OK;
        } else {
                return YAPP_INPUT_VALUE_ERR;
        }
}
#include <SFML/Graphics.hpp>
#include <iostream>
#include "display.hpp"

#define YAPP_DEF_RESOLUTION_X 800
#define YAPP_DEF_RESOLUTION_Y 600

YAPP::defaultMap::defaultMap(sf::RenderWindow* aWindow) {
        rows = defaultMapRows;
        cols = defaultMapColumns;
        window = aWindow;

        sf::Vector2u size = window->getSize();
        rowPixels = size.y / rows;
        colsPixels  = size.x / cols;

        for(int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++)
                {
                        map[i][j] = 1;
                }
                
        }
        std::cout << "Row number      : " << rows << std::endl;
        std::cout << "Col number      : " << cols << std::endl;
        std::cout << "Pixels per Row  : " << rowPixels << std::endl;
        std::cout << "Pixels per Col  : " << colsPixels << std::endl;
    }
/*
Draw the map on the main rendering window, this window is defined in the 
initialization of the map. This will draw to the window all the rectangles, 
which is ineficient and the user will feel the performance drop when using
YAPP-SFML, this is not desired to update the states in the map.
*/
void YAPP::defaultMap::drawMap() {

        sf::RectangleShape rect(sf::Vector2f(colsPixels, rowPixels));
        rect.setOutlineColor(sf::Color::Yellow);
        rect.setOutlineThickness(defaultMapGridThickness);
        rect.setFillColor(sf::Color::Blue);
        rect.setSize(sf::Vector2f(rowPixels, colsPixels));

        for(int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->cols; j++)
                {
                        if(map[i][j] == 1) { 
                                rect.setPosition(sf::Vector2f(j * colsPixels,
                                                                i * rowPixels));
                                window->draw(rect);
                                                
                                
                        }
                }
                
        }
}
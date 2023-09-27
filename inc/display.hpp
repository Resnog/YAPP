
#ifndef YAPP_DISPLAY_H
#define YAPP_DISPLAY_H

#include <array>
#include <SFML/Graphics.hpp>

#define defaultMapRows (60/2)
#define defaultMapColumns (80/2)

#define defaultGridThickness (0.5)

class defaultMap {

    public:
        unsigned int rows;
        unsigned int cols;
        unsigned int rowPixels;
        unsigned int colsPixels;
        sf::RenderWindow* window;
        std::array<std::array<int, defaultMapColumns>, defaultMapRows> map;

        defaultMap(sf::RenderWindow* aWindow);
        
        // Update map elements in window
        void update();

        // Draw map in window
        void drawMap();
};

#endif // YAPP_DISPLAY_H

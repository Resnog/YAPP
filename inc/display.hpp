
#ifndef YAPP_DISPLAY_H
#define YAPP_DISPLAY_H

#include <array>
#include <SFML/Graphics.hpp>

namespace YAPP {
    #define defaultMapRows (60/2)
    #define defaultMapColumns (80/2)

    #define defaultMapGridThickness (0.5)

    /*
    The defaultMap class generates a map with the default options to run algorithms,
    this is the main class to test YAPP-SFML functionalities. The map consists on a 
    grid of N rows and M colums, the YAPP window currently has a hardcoded resolution
    of 800x600, to simplify the exercise.
    */
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

}
#endif // YAPP_DISPLAY_H

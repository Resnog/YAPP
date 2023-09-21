
#ifndef #define YAPP_DISPLAY_H

#YAPP_DEF_RESOLUTION_X 800
#define YAPP_DEF_RESOLUTION_Y 600

#include <array>
#include <SFML/Graphics.hpp>

#define defaultMapRowSize (6)
#define defaultMapColumnSize (8)

class defaultMap {

    public:
        std::array<std::array<int, defaultMapColumnSize>, defaultMapRowSize> map;

        defaultMap();
        
        // Update map elements in window
        void update();

        // Fill map with default values
        void defaultSetUp();
};

#endif // YAPP_DISPLAY_H

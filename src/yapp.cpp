#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "display.hpp"

#define YAPP_DEF_RESOLUTION_X 800
#define YAPP_DEF_RESOLUTION_Y 600

int main(int argc, char *argv[])
{
    // Main YAPP window
    sf::RenderWindow window(sf::VideoMode(YAPP_DEF_RESOLUTION_X, 
                                          YAPP_DEF_RESOLUTION_Y),
                                          "Yet Another Path Planner");

    defaultMap map(&window);
    

    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();
        }
        map.drawMap();

        window.display();
    }
   
    return 0;
}


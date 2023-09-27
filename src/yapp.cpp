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
    
    // TODO Create the algorithm solver, an easy start would be A-Star
    // since it is done in another repo

    // Map display loop
    while (window.isOpen())
    {
        window.clear();
        sf::Event event;
        // Event loop
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();
            
            // TODO: Make an event to handle the map update
        }
        // NOTE: This map display is for testing the map, not the final state
        map.drawMap();

        window.display();
    }
   
    return 0;
}


#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "display.hpp"
#include "yapp.hpp"


int main(int argc, char *argv[])
{

    // Main YAPP window
    sf::RenderWindow window(sf::VideoMode(YAPP_DEF_RESOLUTION_X, 
                                          YAPP_DEF_RESOLUTION_Y),
                                          "Yet Another Path Planner");

    YAPP::SquaredMap map(&window);
    map.loadDefault();
    // TODO Create the algorithm solver, an easy start would be A-Star
    // since it is done in another repo

    // Map display loop
    while (window.isOpen())
    {
        
        sf::Event event;
        // Event loop
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)

                window.close();
            
        }

        window.clear();

        // NOTE: This map display is for testing the map, not the final state
        map.draw();

        window.display();
    }
   
    return 0;
}


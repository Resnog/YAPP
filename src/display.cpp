#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "display.hpp"

defaultMap::defaultMap() {
        std::cout << "Row number: " << this->map.size() << std::endl;
        std::cout << "Col number: " << this->map[0].size() << std::endl;
    }

int main(int argc, char *argv[])
{
    // Main YAPP window
    // sf::RenderWindow window(sf::VideoMode(YAPP_DEF_RESOLUTION_X, 
    //                                       YAPP_DEF_RESOLUTION_Y),
    //                                       "Yet Another Path Planner");

    defaultMap map;

    // while (window.isOpen())
    // {
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         if (event.type == sf::Event::Closed)

    //             window.close();
    //     }
    //     window.display();
    // }

    
    return 0;
}


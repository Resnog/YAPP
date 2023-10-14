#include <iostream>
#include <vector>
#include "map.hpp"
#include "yapp.hpp"
#include <SFML/Graphics.hpp>


int main(int argc, char *argv[])
{

    YAPP::YAPP_ERR yappGuiErr = YAPP::YAPP_OK;
    // Main YAPP window
    sf::RenderWindow window(sf::VideoMode(YAPP_DEF_RESOLUTION_X, 
                                          YAPP_DEF_RESOLUTION_Y),
                                          "Yet Another Path Planner");

    YAPP::SquaredMap map(&window);
    map.loadDefault();
    // TODO Create the algorithm solver, an easy start would be A-Star
    // since it is done in another repo

    // Color one rectangle
    yappGuiErr = map.changeSquareColor(5,5, sf::Color::Red);
    map.shapeMap->at( map.cols*2 +2 ).setFillColor(sf::Color::Green);
    // Map display loop
    while (window.isOpen())
    {
        
        sf::Event event;
        // Event loop
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            
            case sf::Event::MouseButtonPressed:
                if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    sf::Vector2i position = sf::Mouse::getPosition(window);
                    std::cout << "I'm at -- X: " << position.x << " Y: " << position.y << std::endl;
                    std::cout << "At cell-- X: " << position.x/map.colsPixels 
                                << " Y: " << position.y/map.rowPixels << std::endl;
                    map.changeSquareColor( position.x/map.colsPixels,
                                            position.y/map.rowPixels,
                                            sf::Color::Blue);
                }

            default:
                break;
            }
        }

        window.clear();

        // NOTE: This map display is for testing the map, not the final state
        map.draw();

        window.display();
    }
   
    return YAPP::YAPP_OK;
}


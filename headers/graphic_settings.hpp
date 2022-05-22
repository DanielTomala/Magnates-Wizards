#ifndef GRAPHIC_SETTINGS_HPP
#define GRAPHIC_SETTINGS_HPP
#include <SFML/Graphics.hpp>

class GraphicSettings{
    public:
        GraphicSettings();

        std::string title;
        sf::VideoMode resolution;
    	std::vector<sf::VideoMode> videoModes;
        sf::ContextSettings contextSettings;
        

};

#endif
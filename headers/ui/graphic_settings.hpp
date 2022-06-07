#ifndef GRAPHIC_SETTINGS_HPP
#define GRAPHIC_SETTINGS_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class GraphicSettings
/*
    Graphic settings of rendered window
*/
{
public:
    GraphicSettings();

    std::string title;
    sf::VideoMode resolution;
    sf::ContextSettings contextSettings;
    unsigned int frameLimit;
};

#endif
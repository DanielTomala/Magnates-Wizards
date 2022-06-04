#include "../../headers/ui/graphic_settings.hpp"
#include <iostream>

GraphicSettings::GraphicSettings()
{
    this->title = "Magnates & Wizards";
    this->resolution = sf::VideoMode::getDesktopMode();
    this->contextSettings.antialiasingLevel = 0;
    this->frameLimit = 60;
}
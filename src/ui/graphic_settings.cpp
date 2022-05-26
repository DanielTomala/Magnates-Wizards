#include "../../headers/ui/graphic_settings.hpp"
#include <iostream>

GraphicSettings::GraphicSettings()
{
    this->title = "Magnaci i czarodzieje";
    this->resolution = sf::VideoMode::getDesktopMode();
}
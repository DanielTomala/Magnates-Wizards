#include "../../headers/ui/graphic_settings.hpp"

GraphicSettings::GraphicSettings(){
    this->title = "Magnaci i czarodzieje";
    this->resolution = sf::VideoMode::getDesktopMode();
    //this->resolution = sf::VideoMode(1920, 1080);
    this->contextSettings.antialiasingLevel = 0;
}
#include "../headers/graphic_settings.hpp"

GraphicSettings::GraphicSettings(){
    this->title = "Magnaci i czarodzieje";
    this->resolution = sf::VideoMode::getDesktopMode();
    this->contextSettings.antialiasingLevel = 0;
    this->videoModes = sf::VideoMode::getFullscreenModes();
}
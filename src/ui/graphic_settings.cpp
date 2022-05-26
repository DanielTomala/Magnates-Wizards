#include "../../headers/ui/graphic_settings.hpp"

GraphicSettings::GraphicSettings(){
    this->title = "Magnaci i czarodzieje";
    //Irek
    this->resolution = sf::VideoMode::getDesktopMode();
    //Daniel
    //this->resolution = sf::VideoMode(1920, 1080);
    this->contextSettings.antialiasingLevel = 0;
}
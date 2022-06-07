#include "../../headers/ui/loads.hpp"
#include <iostream>
Loads::Loads(float topLeftX, float topLeftY, float radius, sf::Color fillColor)
{

    this->fillColor = fillColor;

    this->firstLoad.setPosition(sf::Vector2f(topLeftX, topLeftY));
    this->firstLoad.setRadius(radius);
    this->firstLoad.setFillColor(fillColor);

    this->secondLoad.setPosition(sf::Vector2f(topLeftX, topLeftY + 15));
    this->secondLoad.setRadius(radius);
    this->secondLoad.setFillColor(fillColor);

    this->thirdLoad.setPosition(sf::Vector2f(topLeftX, topLeftY + 30));
    this->thirdLoad.setRadius(radius);
    this->thirdLoad.setFillColor(fillColor);
}

Loads::~Loads()
{
}

void Loads::changePosition(float topLeftX, float topLeftY)
{
    this->firstLoad.setPosition(sf::Vector2f(topLeftX, topLeftY));
    this->secondLoad.setPosition(sf::Vector2f(topLeftX, topLeftY + 15));
    this->thirdLoad.setPosition(sf::Vector2f(topLeftX, topLeftY + 30));
}

void Loads::update(unsigned int loadsNumber)
{
    firstLoad.setFillColor(sf::Color::Transparent);
    secondLoad.setFillColor(sf::Color::Transparent);
    thirdLoad.setFillColor(sf::Color::Transparent);
    if (loadsNumber >= 1)
    {
        firstLoad.setFillColor(fillColor);
    }
    if (loadsNumber >= 2)
    {
        secondLoad.setFillColor(fillColor);
    }
    if (loadsNumber >= 3)
    {
        thirdLoad.setFillColor(fillColor);
    }
}

void Loads::render(sf::RenderTarget &window)
{
    window.draw(this->firstLoad);
    window.draw(this->secondLoad);
    window.draw(this->thirdLoad);
}

#ifndef LOADS_HPP
#define LOADS_HPP

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class Loads
{
private:
    sf::CircleShape firstLoad;
    sf::CircleShape secondLoad;
    sf::CircleShape thirdLoad;
    sf::Color fillColor;

public:
    Loads(float topLeftX, float topLeftY, float radius, sf::Color fillColor);
    ~Loads();
    void changePosition(float topLeftX, float topLeftY);
    void update(unsigned int loadsNumber);
    void render(sf::RenderTarget &window);
};

#endif
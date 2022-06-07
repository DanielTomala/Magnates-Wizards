#ifndef HPBAR_HPP
#define HPBAR_HPP

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class HPBar
/*
    HP is showed next to hero
    has bar proportional to hero current HP
*/
{
private:
    sf::RectangleShape background; // shape of bar
    sf::RectangleShape maxBar; // full hp bar
    sf::RectangleShape currentBar; // bar proportional to current hp
    sf::Text description; // currentHP/maxHP
    unsigned int maxHP;
    std::shared_ptr<sf::Font> font;

public:
    HPBar(float topLeftX, float topLeftY, float width, float height,
          std::shared_ptr<sf::Font> font, unsigned int maxHP);
    ~HPBar();
    void changePosition(const sf::Vector2f &newPostion);
    void update(const unsigned int &HP);
    void render(sf::RenderTarget &window);
};

#endif

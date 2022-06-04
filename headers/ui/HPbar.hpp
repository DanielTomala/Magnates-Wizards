#ifndef HPBAR_HPP
#define HPBAR_HPP

#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class HPBar
{
private:
    sf::RectangleShape background;
    sf::RectangleShape maxBar;
    sf::RectangleShape currentBar;
    sf::Text description;
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

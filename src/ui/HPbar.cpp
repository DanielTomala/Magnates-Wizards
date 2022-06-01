#include "../../headers/ui/HPbar.hpp"
#include <iostream>
HPBar::HPBar(float topLeftX, float topLeftY, float width, float height,
             std::shared_ptr<sf::Font> font, unsigned int maxHP)
{

    this->maxHP = maxHP;
    this->font = font;

    this->background.setPosition(sf::Vector2f{topLeftX, topLeftY});
    this->background.setSize(sf::Vector2f{width, height});
    this->background.setOutlineColor(sf::Color::Black);
    this->background.setOutlineThickness(3.f);

    this->maxBar.setPosition(sf::Vector2f{topLeftX, topLeftY});
    this->maxBar.setSize(sf::Vector2f{width, height});
    this->maxBar.setFillColor(sf::Color::Yellow);

    this->currentBar.setPosition(sf::Vector2f{topLeftX, topLeftY});
    this->currentBar.setSize(sf::Vector2f{width, height});
    this->currentBar.setFillColor(sf::Color::Green);

    float textX = topLeftX + (width / 2) - 15;
    float textY = topLeftY;
    this->description.setPosition(sf::Vector2f{textX, textY});
    this->description.setFillColor(sf::Color::Black);
    this->description.setStyle(sf::Text::Bold);
    this->description.setFont(*this->font);
    this->description.setCharacterSize(height);
    this->description.setString(std::to_string(maxHP) + "/" + std::to_string(maxHP));
}

HPBar::~HPBar()
{
}

void HPBar::changePosition(sf::Vector2f newPostion)
{
    this->background.setPosition(newPostion);
    this->maxBar.setPosition(newPostion);
    this->currentBar.setPosition(newPostion);
    float textX = newPostion.x + (this->background.getGlobalBounds().width / 2) - 15;
    float textY = newPostion.y;
    this->description.setPosition(sf::Vector2f{textX, textY});
}

void HPBar::update(unsigned int HP)
{
    // sf::Vector2f size = this->maxBar.getSize();
    float scale = (float)HP / this->maxHP;
    this->currentBar.setScale(sf::Vector2f{scale, 1.f});
    this->description.setString(std::to_string(HP) + "/" + std::to_string(maxHP));
}

void HPBar::render(sf::RenderTarget &window)
{
    window.draw(this->background);
    window.draw(this->maxBar);
    window.draw(this->currentBar);
    window.draw(this->description);
}

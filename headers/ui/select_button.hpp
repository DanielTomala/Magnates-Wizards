#ifndef SELECT_BUTTON_HPP
#define SELECT_BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <memory>
#include "../gameplay/game_controller.hpp"

enum SelectButtonState
{
    NotChoosen,
    Choosen
};

class SelectButton
{
private:
    SelectButtonState state;
    sf::Texture texture;
    sf::RectangleShape rect;

    sf::Color notChoosenColor;
    sf::Color choosenColor;
    bool clicked;
    bool hovered;
    std::string description;
    Player player;
    HeroType heroType;

public:
    SelectButton(float topLeftX, float topLeftY, float width, float height,
                 const sf::Texture &texture, sf::Color choosenCollor,
                 std::string description, Player player, HeroType heroType);
    ~SelectButton();

    bool isChoosen() const;
    bool isHovered() const;

    HeroType getHeroType() const;
    Player getPlayer() const;
    std::string getDescription() const;

    void update(const sf::Vector2i &mousePosition);
    void render(sf::RenderTarget &window);
};

#endif

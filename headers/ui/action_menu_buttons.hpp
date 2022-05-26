#ifndef ACTION_MENU_BUTTONS_HPP
#define ACTION_MENU_BUTTONS_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "../game_logic/field.hpp"
#include "./button.hpp"

class ActionMenu
{
public:
    ActionMenu();
    ActionMenu(float topLeftX, float topLeftY, float width, float height,
               const sf::Texture &texture, std::shared_ptr<Button> parent);
    ActionMenu(sf::Vector2f position, sf::Vector2f size, const sf::Texture &texture, std::shared_ptr<Button> parent);
    ~ActionMenu();

    bool isMoveClicked();
    bool isAttackClicked();
    bool isHealClicked();
    bool shouldBeClosed();
    std::shared_ptr<Field> getField();

    void update(const sf::Vector2i &mousePosition);
    void render(sf::RenderTarget &window);

private:
    sf::Texture texture;
    sf::RectangleShape rect;
    sf::Color defaultColor;
    sf::Color hoveredColor;
    bool moveClicked;
    bool attackClicked;
    bool healClicked;
    bool close;
    std::shared_ptr<Field> field;
    std::shared_ptr<Button> parentButton;
};
#endif
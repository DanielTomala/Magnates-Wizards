#ifndef ACTION_MENU_BUTTONS_HPP
#define ACTION_MENU_BUTTONS_HPP

#include <SFML/Graphics.hpp>
#include <memory>

#include "../game_logic/field.hpp"
#include "./button.hpp"

enum ActionNumber
{
    one,
    two,
    three
};

class ActionMenu
{
public:
    ActionMenu();
    ActionMenu(float topLeftX, float topLeftY, float width, float height,
               const sf::Texture &texture, std::shared_ptr<Button> parent, std::shared_ptr<Field> field, ActionNumber actionNumber);
    ActionMenu(sf::Vector2f position, sf::Vector2f size, const sf::Texture &texture, std::shared_ptr<Button> parent, std::shared_ptr<Field> field, ActionNumber actionNumber);
    ~ActionMenu();

    bool isMoveClicked();
    bool isAttackClicked();
    bool isHealClicked();
    bool shouldBeClosed();
    std::shared_ptr<Field> getField();
    std::shared_ptr<Button> getParentButton();

    void update(const sf::Vector2i &mousePosition);
    void render(sf::RenderTarget &window);

private:
    ActionNumber actionNumber;
    sf::Texture texture;
    sf::RectangleShape rect;
    sf::Color defaultColor;
    sf::Color hoveredColor;
    bool moveClicked;
    bool attackClicked;
    bool healClicked;
    bool mouseHold;
    bool pressed;
    bool close;
    bool doNotHide;
    std::shared_ptr<Field> field;
    std::shared_ptr<Button> parentButton;
};
#endif
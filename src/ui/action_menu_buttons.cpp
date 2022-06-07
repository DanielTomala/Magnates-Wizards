#include "../../headers/ui/action_menu_buttons.hpp"
#include <iostream>

ActionMenu::ActionMenu() {}

ActionMenu::ActionMenu(float topLeftX, float topLeftY, float width, float height,
                       const sf::Texture &texture, std::shared_ptr<Button> parent, std::shared_ptr<Field> field, ActionNumber actionNumber)
{
    this->rect.setPosition(sf::Vector2f(topLeftX, topLeftY));
    this->rect.setSize(sf::Vector2f(width, height));
    this->rect.setTexture(&texture, true);
    this->field = field;

    this->actionNumber = actionNumber;
    this->parentButton = parent;
    this->moveClicked = false;
    this->attackClicked = false;
    this->healClicked = false;
    this->mouseHold = false;
    this->pressed = false;
    this->close = false;
    // this->doNotHide = false;
    this->defaultColor = this->rect.getFillColor();
    sf::Color color;
    color.r = 179;
    color.g = 179;
    color.b = 204;
    this->hoveredColor = color;
}

ActionMenu::ActionMenu(sf::Vector2f position, sf::Vector2f size, const sf::Texture &texture, std::shared_ptr<Button> parent, std::shared_ptr<Field> field, ActionNumber actionNumber)
{
    this->rect.setPosition(position);
    this->rect.setSize(size);
    this->rect.setTexture(&texture, true);
    this->field = field;

    this->actionNumber = actionNumber;
    this->parentButton = parent;
    this->moveClicked = false;
    this->attackClicked = false;
    this->healClicked = false;
    this->mouseHold = false;
    this->pressed = false;
    this->close = false;
    // this->doNotHide = false;
    this->defaultColor = this->rect.getFillColor();
    sf::Color color;
    color.r = 179;
    color.g = 179;
    color.b = 204;
    this->hoveredColor = color;
}

ActionMenu::~ActionMenu()
{
}

bool ActionMenu::isMoveClicked()
{
    return this->moveClicked;
}
bool ActionMenu::isAttackClicked()
{
    return this->attackClicked;
}
bool ActionMenu::isHealClicked()
{
    return this->healClicked;
}
bool ActionMenu::shouldBeClosed()
{
    return this->close;
}

std::shared_ptr<Field> ActionMenu::getField()
{
    return this->field;
}

std::shared_ptr<Button> ActionMenu::getParentButton()
{
    return this->parentButton;
}

void ActionMenu::update(const sf::Vector2i &mousePosition)
{
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
        this->rect.getGlobalBounds().contains(sf::Vector2f(mousePosition)) &&
        this->mouseHold == false)
    {
        this->pressed = true;
        this->mouseHold = true;
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Left) &&
             this->rect.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
    {
        this->mouseHold = true;
    }

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false)
    {
        if (this->rect.getGlobalBounds().contains(sf::Vector2f(mousePosition)) &&
            this->pressed)
        {
            auto rectWidth = rect.getSize().x;
            auto rectStartX = rect.getPosition().x;
            // Attack
            if (this->actionNumber == ActionNumber::one)
            {
                healClicked = false;
                moveClicked = false;
                attackClicked = true;
            }
            else if (this->actionNumber == ActionNumber::two)
            {
                // Move
                if (mousePosition.x < (rectStartX + rectWidth * 0.5))
                {
                    healClicked = false;
                    moveClicked = true;
                    attackClicked = false;
                }
                // Attack
                else
                {
                    healClicked = false;
                    moveClicked = false;
                    attackClicked = true;
                }
            }
            else if (this->actionNumber == ActionNumber::three)
            {
                // Heal
                if (mousePosition.x < (rectStartX + rectWidth * 0.33))
                {
                    healClicked = true;
                    moveClicked = false;
                    attackClicked = false;
                }
                // Move
                else if (mousePosition.x < (rectStartX + rectWidth * 0.66))
                {
                    healClicked = false;
                    moveClicked = true;
                    attackClicked = false;
                }
                // Attack
                else
                {
                    healClicked = false;
                    moveClicked = false;
                    attackClicked = true;
                }
            }
        }
        this->pressed = false;
        this->mouseHold = false;
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        this->close = true;
    }
}
void ActionMenu::render(sf::RenderTarget &window)
{
    window.draw(this->rect);
}
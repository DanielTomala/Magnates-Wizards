#include "../../headers/ui/select_button.hpp"

SelectButton::SelectButton(float topLeftX, float topLeftY, float width, float height,
                           const sf::Texture &texture, sf::Color choosenCollor, std::string description, Player player, HeroType heroType)
{
    this->heroType = heroType;
    this->player = player;
    this->description = description;
    this->clicked = false;
    this->hovered = false;
    this->state = NotChoosen;
    this->texture = texture;

    this->rect.setPosition(sf::Vector2f(topLeftX, topLeftY));
    this->rect.setSize(sf::Vector2f(width, height));

    this->rect.setTexture(&this->texture, true);

    // if (player == Player::Second)
    // {
    //     this->rect.setScale(-1, 1);
    // }

    // this->rect.setOutlineColor(sf::Color::Black);
    // this->rect.setOutlineThickness(1.f);

    this->notChoosenColor = this->rect.getFillColor();
    this->choosenColor = choosenCollor;
}

SelectButton::~SelectButton() {}

std::string SelectButton::getDescription() const
{
    std::string dsc = this->description;
    if (this->isChoosen())
    {
        switch (this->player)
        {
        case First:
            dsc += "Choosen by 1\n";
            break;
        case Second:
            dsc += "Choosen by 2\n";
            break;
        }
    }
    return dsc;
}

HeroType SelectButton::getHeroType() const
{
    return this->heroType;
}

Player SelectButton::getPlayer() const
{
    return this->player;
}

bool SelectButton::isChoosen() const
{
    if (this->state == Choosen)
    {
        return true;
    }
    return false;
}

void SelectButton::update(const sf::Vector2i &mousePosition)
{
    if (this->rect.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
    {
        this->hovered = true;

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            this->clicked = true;
        }
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) == false && clicked == true)
        {
            this->clicked = false;
            if (this->isChoosen())
            {
                this->state = NotChoosen;
            }
            else
            {
                this->state = Choosen;
            }
        }
    }
    else
    {
        this->hovered = false;
    }
    switch (this->state)
    {
    case NotChoosen:
        this->rect.setFillColor(this->notChoosenColor);
        break;
    case Choosen:
        this->rect.setFillColor(this->choosenColor);
        break;
    }
}

bool SelectButton::isHovered() const
{
    return this->hovered;
}

void SelectButton::render(sf::RenderTarget &window)
{
    window.draw(this->rect);
}

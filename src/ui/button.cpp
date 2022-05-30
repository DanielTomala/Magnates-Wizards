#include "../../headers/ui/button.hpp"

Button::Button(float topLeftX, float topLeftY, float width, float height,
               std::shared_ptr<sf::Font> font, std::string text, unsigned int textSize,
               const sf::Texture &texture, sf::Color normalColor, sf::Color highlightedColor, sf::Color clickedColor,
               unsigned int id)
{
    this->highlighted = false;
    this->pressed = false;
    this->mouseHold = false;
    this->active = false;
    this->id = id;
    this->texture = texture;

    this->rect.setPosition(sf::Vector2f(topLeftX, topLeftY));
    this->rect.setSize(sf::Vector2f(width, height));
    this->rect.setFillColor(normalColor);

    this->rect.setTexture(&this->texture, true);


    this->font = font;
    this->text.setFont(*this->font);
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Black);
    this->text.setCharacterSize(textSize);
    this->text.setStyle(sf::Text::Bold);

    this->text.setPosition(
        this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
        this->rect.getPosition().y + (this->rect.getGlobalBounds().height - this->text.getGlobalBounds().height - textSize) / 2.f);
    this->normalColor = normalColor;
    this->highlightedColor = highlightedColor;
    this->clickedColor = clickedColor;
}

Button::~Button() {}

bool Button::isClicked()
{
    if (this->active)
    {
        this->active = false;
        return true;
    }
    return false;
}

std::string Button::getText() const
{
    return this->text.getString();
}

unsigned int Button::getId() const
{
    return this->id;
}

sf::RectangleShape Button::getRect() const
{
    return this->rect;
}

void Button::setText(const std::string &text)
{
    this->text.setString(text);
}

void Button::setId(const unsigned int &id)
{
    this->id = id;
}

void Button::setTexture(const sf::Texture &texture)
{
    this->texture = texture;
}

void Button::update(const sf::Vector2i &mousePosition)
{
    if(this->rect.getGlobalBounds().contains(sf::Vector2f(mousePosition))){
        this->highlighted = true;
    }
    else this->highlighted = false;
    
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&\
    this->rect.getGlobalBounds().contains(sf::Vector2f(mousePosition))&&\
    this->mouseHold == false)
    {
        this->highlighted = false;
        this->pressed = true;
        this->mouseHold = true;
    }
    else if(sf::Mouse::isButtonPressed(sf::Mouse::Left) &&\
    this->rect.getGlobalBounds().contains(sf::Vector2f(mousePosition)))
    {
        this->mouseHold = true;
    }
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left) == false){
        if(this->rect.getGlobalBounds().contains(sf::Vector2f(mousePosition))&&\
        this->pressed)
        {
            this->active = true;
        }
        this->pressed = false;
        this->mouseHold = false;
    }
    
    this->rect.setFillColor(this->normalColor);
    
    if(this->highlighted){
        this->rect.setFillColor(this->highlightedColor);
    }
    if(this->pressed){
        this->rect.setFillColor(this->clickedColor);
    }
}

void Button::setTexture(const sf::Texture &texture)
{
    this->texture = texture;
}


void Button::render(sf::RenderTarget &window)
{
    window.draw(this->rect);
    window.draw(this->text);
}

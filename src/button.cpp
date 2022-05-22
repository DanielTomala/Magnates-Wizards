#include "../headers/button.hpp"

Button::Button(){};

Button::Button(float topLeftX, float topLeftY, float width, float height,
        std::shared_ptr<sf::Font> font, std::string text,
        sf::Color normalColor, sf::Color highlightedColor, sf::Color clickedColor,
        unsigned int id)
        {
            this->id = id;
            this->state = normal;

            this->rect.setPosition(sf::Vector2f(topLeftX, topLeftY));
            this->rect.setSize(sf::Vector2f(width, height));
            this->rect.setFillColor(normalColor);
            this->rect.setOutlineColor(sf::Color::Black);
            this->rect.setOutlineThickness(1.f);

            this->font = font;
            this->text.setFont(*this->font);
            this->text.setString(text);
            this->text.setFillColor(sf::Color::Black);
            this->text.setCharacterSize(14);

            this->text.setPosition(
                this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		        this->rect.getPosition().y
            );

            this->highlightedColor = highlightedColor;
            this->clickedColor = clickedColor;
        }

Button::~Button() {}

bool Button::isClicked() const{
    if(this->state == clicked){
        return true;
    }
    return false;
}

std::string Button::getText() const{
    return this->text.getString();
}

unsigned int Button::getId() const{
    return this->id;
}

void Button::setText(const std::string &text){
    this->text.setString(text);
}

void Button::setId(const unsigned int &id){
    this->id = id;
}

void Button::update(const sf::Vector2i& mousePosition){

    this->state = normal;

    if(this->rect.getGlobalBounds().contains(sf::Vector2f(mousePosition))){
        this->state = highlighted;

        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){
            this->state = clicked;
        }
    }

    switch(this->state){
        case normal:
            this->rect.setFillColor(this->normalColor);
            break;
        case highlighted:
            this->rect.setFillColor(this->highlightedColor);
            break;
        case clicked:
            this->rect.setFillColor(this->clickedColor);
            break;
    }
}

void Button::render(sf::RenderTarget &window){
    window.draw(this->rect);
    window.draw(this->text);
}


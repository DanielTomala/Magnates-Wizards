#include "../headers/button.hpp"


Button::Button(float topLeftX, float topLeftY, float width, float height,
        std::shared_ptr<sf::Font> font, std::string text, unsigned int textSize,
        const sf::Texture& texture, sf::Color normalColor, sf::Color highlightedColor, sf::Color clickedColor,
        unsigned int id)
        {
            this->id = id;
            this->state = normal;
            this->texture = texture;
            
            this->rect.setPosition(sf::Vector2f(topLeftX, topLeftY));
            this->rect.setSize(sf::Vector2f(width, height));
            this->rect.setFillColor(normalColor);

            this->rect.setTexture(&this->texture, true);
            this->rect.setOutlineColor(sf::Color::Black);
            this->rect.setOutlineThickness(1.f);


            this->font = font;
            this->text.setFont(*this->font);
            this->text.setString(text);
            this->text.setFillColor(sf::Color::Black);
            this->text.setCharacterSize(textSize);
            this->text.setStyle(sf::Text::Bold);

            this->text.setPosition(
                this->rect.getPosition().x + (this->rect.getGlobalBounds().width / 2.f) - this->text.getGlobalBounds().width / 2.f,
		        this->rect.getPosition().y + (this->rect.getGlobalBounds().height - this->text.getGlobalBounds().height - textSize) /2.f
            );
            this->normalColor = normalColor;
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
            this->rect.setTexture(&this->texture);
            this->rect.setFillColor(this->normalColor);
            break;
        case highlighted:
            this->rect.setFillColor(this->highlightedColor);
            this->rect.setTexture(&this->texture);
            break;
        case clicked:
            this->rect.setFillColor(this->clickedColor);
            this->rect.setTexture(&this->texture);
            break;
    }
}

void Button::render(sf::RenderTarget &window){
    window.draw(this->rect);
    window.draw(this->text);
}


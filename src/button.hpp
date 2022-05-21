#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <memory>

enum ButtonState{
    normal,
    highlighted,
    clicked
};

class Button{

    private:
        ButtonState state;
        unsigned int id;


        sf::RectangleShape rect;
        std::shared_ptr<sf::Font> font;
        sf::Text text;

        sf::Color normalColor;
        sf::Color highlightedColor;
        sf::Color clickedColor;
    
    public:
        Button(float topLeftX, float topLeftY, float width, float height,
        std::shared_ptr<sf::Font> font,
        sf::Color normalColor, sf::Color highlightedColor, sf::Color clickedColor,
        unsigned int id);

        ~Button();



};

#endif
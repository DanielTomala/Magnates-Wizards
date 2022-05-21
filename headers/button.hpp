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
        std::shared_ptr<sf::Font> font, std::string text,
        sf::Color normalColor, sf::Color highlightedColor, sf::Color clickedColor,
        unsigned int id);

        ~Button();

        bool isClicked() const;
        std::string getText() const;
        unsigned int getId() const;

        void setText(const std::string &text);
        void setId(const unsigned int &id);

        void update(const sf::Vector2i& mousePosition);
        void render(std::shared_ptr<sf::RenderTarget> window);
};

#endif
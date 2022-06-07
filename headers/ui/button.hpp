#ifndef BUTTON_HPP
#define BUTTON_HPP

#include <SFML/Graphics.hpp>
#include <memory>

class Button
/*
    GUI button
    has rectangle shape and texture
    color of texture depends on button state
    reacts to relase of mouse button after click
*/
{
private:
    unsigned int id; //can be repeated, useful in calculating coords
    bool active; // if action has to be done, button pressed and relased
    bool pressed; 
    bool mouseHold; 
    bool highlighted; // if mouse is on button

    sf::Texture texture; // texture of button background
    sf::RectangleShape rect; // shape of button
    std::shared_ptr<sf::Font> font;
    sf::Text text;

    sf::Color normalColor;
    sf::Color highlightedColor;
    sf::Color clickedColor;

public:
    Button(float topLeftX, float topLeftY, float width, float height,
           std::shared_ptr<sf::Font> font, std::string text, unsigned int textSize,
           const sf::Texture &texture, sf::Color normalColor, sf::Color highlightedColor, sf::Color clickedColor,
           unsigned int id);

    ~Button();

    bool isClicked(); // returns value of active and set active to false if active
    std::string getText() const;
    unsigned int getId() const;
    sf::RectangleShape getRect() const;

    void setTexture(const sf::Texture &texture);
    void setText(const std::string &text);
    void setColor(const sf::Color &color);
    void setId(const unsigned int &id);
    void update(const sf::Vector2i &mousePosition);
    void render(sf::RenderTarget &window);
};

#endif
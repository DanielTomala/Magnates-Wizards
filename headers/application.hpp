#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include "game_controller.hpp"
#include "consts.hpp"
#include <iostream>
#include <filesystem>


class Application{
    public:
        sf::RenderWindow window;
        unsigned int monitor[2] = {sf::VideoMode::getDesktopMode().width, sf::VideoMode::getDesktopMode().height},
            screen[2] = {1000, 600};
        bool fullscreen;
        std::string title = "SFML test";
        sf::Time time, game_time;
        sf::Clock clock, game_clock;
        sf::Vector2i mouse;

        sf::Vector2f topLeft;
        sf::Sprite backgroundSprite;

        std::map<std::string, std::shared_ptr<sf::Texture> > textures;        
        GameController state;

        Application(bool);
        void output();
        void center_window();
        void events(sf::Event);
        void time_update();
        void update();
        void render();
        void run();
        
        void loadBackground();
        void loadTextures();

        void drawBoard();
        void loadFieldsSprites();
        void createBoard();
};   
#endif
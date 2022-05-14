#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <vector>
#include <memory>
#include <SFML/Window.hpp>
#include "board.hpp"
#include "consts.hpp"
#include <iostream>
#include <filesystem>

// sf::Texture backgroundTX,
//             fieldTX,
//             field_greenTX,
//             field_redTX,
//             stoneTX,
//             bowerTX,
//             catapultTX,
//             gnd_druideTX,
//             knightTX,
//             magicianTX,
//             medicTX,
//             ninjaTX,
//             trebuchetTX,
//             wizardTX;

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
        Board board;

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
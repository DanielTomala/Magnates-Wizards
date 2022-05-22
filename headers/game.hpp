#ifndef GAME_HPP
#define GAME_HPP

#include "./states/main_menu_state.hpp"
#include "./states/create_heroes_state.hpp"
#include "./states/game_state.hpp"
#include "./states/player_menu_state.hpp"


class Game{
    private:
        GraphicSettings settings;
        std::shared_ptr<sf::RenderWindow> window;
        StatesStack states;
        
        sf::Event event;
        sf::Clock clock;

        void initVariables();
        void initSettings();
        void initWindow();
        void initStates();
    public:
        Game();
        virtual ~Game();

        void endGame();

        void updateEvents();
        void update();

        void render();

        void run();

};

#endif
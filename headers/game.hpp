#ifndef GAME_HPP
#define GAME_HPP

#include "./states/main_menu_state.hpp"


class Game{
    private:
        GraphicSettings settings;
        StateData stateData;
        std::shared_ptr<sf::RenderWindow> window;
        sf::Event event;

        sf::Clock clock;

        StatesStack states;
        void initVariables();
        void initSettings();
        void initWindow();
        void initStateData();
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
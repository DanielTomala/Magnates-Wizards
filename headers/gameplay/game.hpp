#ifndef GAME_HPP
#define GAME_HPP

#include "../ui/states/main_menu_state.hpp"
#include "../ui/states/create_heroes_state.hpp"
#include "../ui/states/game_state.hpp"
#include "game_controller.hpp"

class Game
{
private:
    GraphicSettings settings;
    sf::RenderWindow *window;
    StatesStack states;
    GameController controller;

    sf::Event event;
    sf::Clock clock;

    void initSettings();
    void initController();
    void initWindow();
    void initStates();

    void updateEvents();
    void update();
    
    void render();
public:
    Game();
    virtual ~Game();

    void run();
};

#endif
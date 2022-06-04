#ifndef STATE_HPP
#define STATE_HPP

#include "../graphic_settings.hpp"
#include "../../gameplay/game_controller.hpp"
#include <memory>
#include <stack>

class State;
typedef std::stack<State *> StatesStack;

class State
{
protected:
    GraphicSettings *settings;      // settings of window
    StatesStack *states;            // stack of states
    sf::RenderWindow *window;       // pointer for window
    GameController *gameController; // game logic

    bool quit;
    std::map<std::string, sf::Texture> textures;

    sf::Vector2i mousePos;

    float xGrid;
    float yGrid;

    void createGrid();

public:
    State(StatesStack *stackPointer,
          sf::RenderWindow *window,
          GraphicSettings *settings,
          GameController *gameController);
    virtual ~State();

    void endState();

    bool getQuit() const;

    virtual void updateMousePosition();
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif
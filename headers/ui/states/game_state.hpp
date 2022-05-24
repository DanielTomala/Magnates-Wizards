#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <tuple>
#include "state.hpp"
#include "../button.hpp"
#include "../../gameplay/game_controller.hpp"

class GameState : public State
{
private:
    sf::Texture backgroundTX;
    sf::RectangleShape backgroundRect;
    sf::Font font;

    std::map<std::string, std::shared_ptr<Button>> buttons;
    std::map<std::tuple<int, int>, std::shared_ptr<Button>> boardButtons;

    void initTextures();
    void initFonts();
    void initGui();
    void resetGui();
    void initBoardButtons();
    void drawBoard();

public:
    GameState(StatesStack *stackPointer,
              sf::RenderWindow *window,
              GraphicSettings *settings,
              GameController *gameController);
    virtual ~GameState();

    void updateSprites();
    void updateButtons();
    void update();

    void renderButtons();
    void render();
};

#endif
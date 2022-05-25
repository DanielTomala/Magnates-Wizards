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
    sf::Sprite actionMenuSprite;
    sf::RectangleShape backgroundRect;
    sf::Font font;

    std::map<std::string, std::shared_ptr<Button>> buttons;
    std::map<std::tuple<int, int>, std::shared_ptr<Button>> boardButtons;

    void initTextures();
    void initFonts();
    void initGui();
    void resetGui();
    void initBoardButtons();
    void showHero(std::shared_ptr<Hero> hero, int buttonX, int buttonY);
    void showActionMenu(std::shared_ptr<Button> button);
    void drawBoard();

public:
    GameState(StatesStack *stackPointer,
              sf::RenderWindow *window,
              GraphicSettings *settings,
              GameController *gameController);
    virtual ~GameState();

    // Test
    void addTestValuesToBoard();
    // End test

    void updateSprites();
    void update();
    void updateButtons();
    void renderHeroes();
    void renderActionMenu();

    void renderButtons();
    void render();
};

#endif
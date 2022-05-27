#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <tuple>
#include "state.hpp"
#include "../button.hpp"
#include "../../gameplay/game_controller.hpp"
#include "../../ui/action_menu_buttons.hpp"
#include "../../ui/button.hpp"
#include "../../ui/HPbar.hpp"

class GameState : public State
{
private:
    sf::Texture backgroundTX;
    sf::RectangleShape backgroundRect;
    sf::Font font;

    std::map<std::string, std::shared_ptr<Button>> buttons;
    std::map<std::tuple<int, int>, std::shared_ptr<Button>> boardButtons;
    std::map<std::shared_ptr<Hero>, std::shared_ptr<HPBar>> HPBars;

    std::optional<std::shared_ptr<ActionMenu>> actionMenu;
    std::optional<std::shared_ptr<Field>> chosenField;
    std::optional<std::shared_ptr<Button>> chosenButton;

    bool actionChosen;

    Player currentPlayer;
    unsigned int actionsLeft;

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

    Player getCurrentPlayer();
    unsigned int getActionsLeft();
    void setCurrentPlayer(Player player);
    void setActionsLeft(unsigned int actionsLeft);
    void changeTurn();

    void updateSprites();
    void update();
    void updateButtons();
    void updateActionMenu();
    void updateHeroPosition(std::shared_ptr<Hero> hero, std::shared_ptr<Button> newField);

    void checkIfActionHasToBeDone();
    void updateHPBars();

    void renderHeroes();
    void renderActionMenu();
    void renderButtons();
    void renderHPBars();

    void render();

    // TEST
    void gameOutput();
    // End TEST
};

#endif
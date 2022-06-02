#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <tuple>
#include "state.hpp"
#include "../button.hpp"
#include "../../gameplay/game_controller.hpp"
#include "../../ui/action_menu_buttons.hpp"
#include "../../ui/button.hpp"
#include "../../ui/HPbar.hpp"
#include "../../ui/loads.hpp"

class GameState : public State
{
public:
    GameState(StatesStack *stackPointer,
              sf::RenderWindow *window,
              GraphicSettings *settings,
              GameController *gameController);
    virtual ~GameState();

    Player getCurrentPlayer();
    unsigned int getActionsLeft();
    void setCurrentPlayer(Player player);
    void setActionsLeft(unsigned int actionsLeft);

    void changeTurn();
    void unfreezeHeores(Player player);
    void updateFrozenHeroes();
    void resetLoads();
    void continueTrebuchetAttack();

    void update();
    void updateSprites();
    void updateButtons();
    void updateActionMenu();
    void updateHeroPosition(std::shared_ptr<Hero> hero, std::shared_ptr<Button> newField);
    void updateHPBars();
    void updateLoads();
    void checkIfActionHasToBeDone();
    bool checkIfGameEnded();

    void renderHeroes();
    void renderActionMenu();
    void renderButtons();
    void renderHPBars();
    void renderLoads();
    void updateTexts();
    void initShapesAndTexts();
    void renderShapesAndTexts();

    void render();

    // TEST
    void gameOutput();
    // End TEST

private:
    sf::Texture backgroundTX;
    sf::RectangleShape backgroundRect;
    sf::Font font;

    std::map<std::string, std::shared_ptr<Button>> buttons;
    std::map<std::tuple<int, int>, std::shared_ptr<Button>> boardButtons;
    std::map<std::shared_ptr<Hero>, std::shared_ptr<HPBar>> HPBars;
    std::map<std::shared_ptr<Hero>, std::shared_ptr<Loads>> loads;

    std::map<std::string, std::shared_ptr<sf::Text>> texts;
    std::map<std::string, std::shared_ptr<sf::RectangleShape>> shapes;

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
};

#endif
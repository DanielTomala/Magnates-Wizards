#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include "board.hpp"

#include <tuple>

class GameController
{
public:
    GameController();
    void startGame();
    void changeTurn();

    Board &getBoard();
    Player getCurrentPlayer();
    unsigned int getActionsLeft();

    void setCurrentPlayer(Player player);
    void setActionsLeft(unsigned int actionsLeft);


private:
    Board board;
    Player currentPlayer;
    unsigned int actionsLeft;

    void buyingPhase();
    void turnPhase();
    bool gameIsContinued();

    void healAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord);
    void moveAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord);
    void attackAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord);
    void useAbilityAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord);
};

#endif
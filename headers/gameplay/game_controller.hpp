#ifndef GAME_CONTROLLER_HPP
#define GAME_CONTROLLER_HPP

#include "../game_logic/board.hpp"
#include "../consts.hpp"

#include <tuple>

class GameController
{
public:
    GameController(){};
    GameController(std::shared_ptr<Board> board);
    void startGame();
    void changeTurn();

    std::shared_ptr<Board> getBoard();
    Player getCurrentPlayer();
    unsigned int getActionsLeft();

    void setCurrentPlayer(Player player);
    void setActionsLeft(unsigned int actionsLeft);

    void healAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField);
    void moveAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField);
    void attackAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField);
    void useAbilityAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord);

private:
    std::shared_ptr<Board> board;
    Player currentPlayer;
    unsigned int actionsLeft;

    void buyingPhase();
    void turnPhase();
    bool gameIsContinued();
};

#endif
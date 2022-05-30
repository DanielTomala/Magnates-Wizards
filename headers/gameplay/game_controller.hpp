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
    void resetController();
    
    std::shared_ptr<Board> getBoard();

    bool healAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField);
    bool moveAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField);
    bool attackAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField);
    void useAbilityAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord);

    bool isFieldInRange(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField, unsigned int range);

private:
    std::shared_ptr<Board> board;


    void buyingPhase();
    void turnPhase();
    bool gameIsContinued();
};

#endif
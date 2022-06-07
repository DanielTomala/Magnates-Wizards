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
    void resetController();

    std::shared_ptr<Board> getBoard();
    std::vector<std::shared_ptr<Hero>> frozenHeroes;
    std::map<std::shared_ptr<Field>, int> trebuchetAttack;

    bool healAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField);
    bool moveAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField);
    bool attackAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField);
    void mageSpecialAttack(std::shared_ptr<Hero> hero, std::shared_ptr<Hero> heroToAttack);
    void iceDruidSpecialAttack(std::shared_ptr<Hero> hero, std::shared_ptr<Hero> heroToAttack);
    void trebuchetSpecialAttack(std::shared_ptr<Field> actionField, unsigned int damage);

    bool isFieldInRange(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField, unsigned int range);

private:
    std::shared_ptr<Board> board;
};

#endif
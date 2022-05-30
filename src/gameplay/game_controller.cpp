#include "../../headers/gameplay/game_controller.hpp"
#include <iostream>

GameController::GameController(std::shared_ptr<Board> board){
    this->board = board;
}

void GameController::resetController(){
    for(auto &row: this->board->getFields()){
        for(auto &field: row){
            field->removeHero();            
        }
    }
}

std::shared_ptr<Board> GameController::getBoard()
{
    return this->board;
}

Player GameController::getCurrentPlayer()
{
    return this->currentPlayer;
}

unsigned int GameController::getActionsLeft()
{
    return this->actionsLeft;
}

void GameController::setCurrentPlayer(Player player)
{
    this->currentPlayer = player;
}

void GameController::setActionsLeft(unsigned int actionsLeft)
{
    this->actionsLeft = actionsLeft;
}

void GameController::startGame()
{
    setActionsLeft(ACTIONS_PER_TURN);
    setCurrentPlayer(Player::First);
    //Call window for buying phase
    buyingPhase();
    //Call window for turn phase
    turnPhase();
}

void GameController::changeTurn()
{
    setActionsLeft(ACTIONS_PER_TURN);
    if (getCurrentPlayer() == Player::First)
    {
        setCurrentPlayer(Player::Second);
    }
    else
    {
        setCurrentPlayer(Player::First);
    }
}

void GameController::buyingPhase()
{
}

void GameController::turnPhase()
{
    while (gameIsContinued())
    {
    }
}

bool GameController::gameIsContinued()
{
    return true;
}

// tuple<row, column>
// Przed wywołaniem tej metody powinno zostać sprawdzone, czy leczony hero należy do naszej drużyny, czy jest w zasięgu i czy może zostać uleczony
void GameController::healAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord)
{
    auto board = this->getBoard();
    auto heroField = board->getFieldByCoordinate(std::get<0>(heroFieldCoord), std::get<1>(heroFieldCoord));
    auto actionField = board->getFieldByCoordinate(std::get<0>(actionFieldCoord), std::get<1>(actionFieldCoord));
    auto hero = heroField->getHero().value(); // Skoro trafiliśmy do tej metody to już raczej nie jest wymagane sprawdzenie czy hero nie jest nullopt
    auto actionHero = actionField->getHero().value();

    if (hero->getType() != HeroType::EMedic)
    {
        throw std::invalid_argument("Only Medic can heal other heroes");
    }

    // unsigned int healPoints = hero.getHealPoints(); // Some medic's method, which return heal points
    unsigned int healPoints = 10;
    actionHero->heal(healPoints);

    // Może dodatkowo, będzie należało odjąć jakieś punkty many medykowi
    actionsLeft--;
}

void GameController::moveAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord)
{
    auto board = this->getBoard();
    auto heroField = board->getFieldByCoordinate(std::get<0>(heroFieldCoord), std::get<1>(heroFieldCoord));
    auto actionField = board->getFieldByCoordinate(std::get<0>(actionFieldCoord), std::get<1>(actionFieldCoord)); // Powinno zostać sprawdzone, że jest puste i czy jest w zasięgu
    auto hero = heroField->getHero().value();                                                                      // Skoro trafiliśmy do tej metody to już raczej nie jest wymagane sprawdzenie czy hero nie jest nullopt

    heroField->removeHero();
    actionField->addHero(hero);

    actionsLeft--;
}

void GameController::attackAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord)
{
    auto board = this->getBoard();
    auto heroField = board->getFieldByCoordinate(std::get<0>(heroFieldCoord), std::get<1>(heroFieldCoord));
    auto actionField = board->getFieldByCoordinate(std::get<0>(actionFieldCoord), std::get<1>(actionFieldCoord));
    auto hero = heroField->getHero().value();         // Skoro trafiliśmy do tej metody to już raczej nie jest wymagane sprawdzenie czy hero nie jest nullopt
    auto actionHero = actionField->getHero().value(); // Hero jest w zasięgu

    actionHero->takeDamage(hero->getWeapon().value().getDamage());
    // actionHero.getWearable().value().takeDurabilityLoss(1); //Jakieś zniszczenie części pancerza
    // hero.getWeapon().value().takeDurabilityLoss(1); //Jakieś zniszczenie broni

    actionsLeft--;
}

void GameController::useAbilityAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord)
{
    auto board = this->getBoard();
    auto heroField = board->getFieldByCoordinate(std::get<0>(heroFieldCoord), std::get<1>(heroFieldCoord));
    auto actionField = board->getFieldByCoordinate(std::get<0>(actionFieldCoord), std::get<1>(actionFieldCoord));
    auto hero = heroField->getHero().value();         // Skoro trafiliśmy do tej metody to już raczej nie jest wymagane sprawdzenie czy hero nie jest nullopt
    auto actionHero = actionField->getHero().value(); // Hero jest w zasięgu

    // Wykonanie akcji specjalnej

    actionsLeft--;
}

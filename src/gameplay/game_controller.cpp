#include "../../headers/gameplay/game_controller.hpp"
#include <iostream>
#include <cmath>

GameController::GameController(std::shared_ptr<Board> board)
{
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


// void GameController::startGame()
// {
//     setActionsLeft(ACTIONS_PER_TURN);
//     setCurrentPlayer(Player::First);
//     // Call window for buying phase
//     buyingPhase();
//     // Call window for turn phase
//     turnPhase();
// }

// void GameController::changeTurn()
// {
//     setActionsLeft(ACTIONS_PER_TURN);
//     if (getCurrentPlayer() == Player::First)
//     {
//         setCurrentPlayer(Player::Second);
//     }
//     else
//     {
//         setCurrentPlayer(Player::First);
//     }
// }

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

//Heal na puste pole wyrzuca bad optional access
// Przed wywołaniem tej metody powinno zostać sprawdzone, czy leczony hero należy do naszej drużyny, czy jest w zasięgu i czy może zostać uleczony
bool GameController::healAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField)
{
    auto hero = heroField->getHero().value();
    auto actionHero = actionField->getHero().value();

    if (hero->getType() != HeroType::EMedic)
    {
        throw std::invalid_argument("Only Medic can heal other heroes");
    }
    if (hero->getOwner() == actionHero->getOwner() && isFieldInRange(heroField, actionField, hero->getWeapon()->getRange()))
    {
        // unsigned int healPoints = hero.getHealPoints(); // Some medic's method, which return heal points
        unsigned int healPoints = 10;
        actionHero->heal(healPoints);
        std::cout << "Healed hero" << std::endl;

        // Może dodatkowo, będzie należało odjąć jakieś punkty many medykowi
        return true;
    }
    return false;
}

bool GameController::moveAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField)
{
    auto hero = heroField->getHero().value();
    if (actionField->isFree() && isFieldInRange(heroField, actionField, hero->getMoveRange()))
    {
        heroField->removeHero();
        actionField->addHero(hero);
        std::cout << "Hero moved" << std::endl;
        return true;
    }
    else
    {
        std::cout << "This field is already occupied or is not in range" << std::endl;
        return false;
    }
}

//Attack na puste pole wyrzuca bad optional access
bool GameController::attackAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField)
{
    auto hero = heroField->getHero().value();
    auto actionHero = actionField->getHero().value();
    if (!actionField->isFree() && hero->getOwner() != actionHero->getOwner() && isFieldInRange(heroField, actionField, hero->getWeapon()->getRange())) // Pytanie czy Hero będzie miał weapon
    {
        actionHero->takeDamage(hero->getWeapon().value().getDamage());
        // actionHero.getWearable().value().takeDurabilityLoss(1); //Jakieś zniszczenie części pancerza
        // hero.getWeapon().value().takeDurabilityLoss(1); //Jakieś zniszczenie broni
        std::cout << "Damage given" << std::endl;
        return true;
    }
    return false;
}

void GameController::useAbilityAction(std::tuple<int, int> heroFieldCoord, std::tuple<int, int> actionFieldCoord)
{
    auto board = this->getBoard();
    auto heroField = board->getFieldByCoordinate(std::get<0>(heroFieldCoord), std::get<1>(heroFieldCoord));
    auto actionField = board->getFieldByCoordinate(std::get<0>(actionFieldCoord), std::get<1>(actionFieldCoord));
    auto hero = heroField->getHero().value();         // Skoro trafiliśmy do tej metody to już raczej nie jest wymagane sprawdzenie czy hero nie jest nullopt
    auto actionHero = actionField->getHero().value(); // Hero jest w zasięgu

    // Wykonanie akcji specjalnej

    // actionsLeft--;
}

bool GameController::isFieldInRange(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField, unsigned int range)
{
    auto heroFieldCoor = this->getBoard()->findFieldCoordinates(heroField);
    auto actionFieldCoor = this->getBoard()->findFieldCoordinates(actionField);
    float distance = std::sqrt(std::pow(std::get<0>(heroFieldCoor) - std::get<0>(actionFieldCoor), 2) + std::pow(std::get<1>(heroFieldCoor) - std::get<1>(actionFieldCoor), 2));
    if (distance <= range)
    {
        return true;
    }
    else
    {
        return false;
    }
}

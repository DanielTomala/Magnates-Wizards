#include "../../headers/gameplay/game_controller.hpp"
#include <iostream>
#include <cmath>

// Constructor
GameController::GameController(std::shared_ptr<Board> board)
{
    this->board = board;
}

void GameController::resetController()
{
    for (auto &row : this->board->getFields())
    {
        for (auto &field : row)
        {
            field->removeHero();
        }
    }
}

// Getters
std::shared_ptr<Board> GameController::getBoard()
{
    return this->board;
}

std::vector<std::shared_ptr<Hero>> GameController::getFrozenHeroes()
{
    return this->frozenHeroes;
}

std::map<std::shared_ptr<Field>, int> GameController::getTrebuchetAttackRepetition()
{
    return this->trebuchetAttackRepetition;
}
// Getters end

// Actions
// Return true if action was successful, else returns false
bool GameController::healAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField)
{
    if (actionField->getHero() == std::nullopt)
    {
        return false;
    }

    auto hero = heroField->getHero().value();
    auto actionHero = actionField->getHero().value();

    if (hero->getType() != HeroType::EMedic)
    {
        throw std::invalid_argument("Only Medic can heal other heroes");
    }
    if (hero->getOwner() == actionHero->getOwner() && isFieldInRange(heroField, actionField, hero->getWeapon().value()->getRange()))
    {
        unsigned int healPoints = hero->getWeapon().value()->getHealPoints();
        actionHero->heal(healPoints);
        return true;
    }
    return false;
}

// Return true if action was successful, else returns false
bool GameController::moveAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField)
{
    auto hero = heroField->getHero().value();
    if (actionField->isFree() && isFieldInRange(heroField, actionField, hero->getMoveRange()))
    {
        heroField->removeHero();
        actionField->addHero(hero);
        return true;
    }
    else
    {
        return false;
    }
}

// Return true if action was successful, else returns falses
bool GameController::attackAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField)
{
    if (actionField->isFree())
    {
        return false;
    }
    auto hero = heroField->getHero().value();
    auto heroToAttack = actionField->getHero().value();
    unsigned int range = hero->getWeapon().value()->getRange();
    if (hero->getOwner() != heroToAttack->getOwner() && isFieldInRange(heroField, actionField, range))
    {
        if (hero->getWeapon() == std::nullopt)
        {
            return false;
        }
        if (hero->getType() == HeroType::EMage)
        {
            mageSpecialAttack(hero, heroToAttack);
        }
        else if (hero->getType() == HeroType::EIceDruid)
        {
            if (hero->getLoads() > 0)
            {
                iceDruidSpecialAttack(hero, heroToAttack);
                hero->setLoads(hero->getLoads() - 1);
            }
            else
            {
                return false;
            }
        }
        else if (hero->getType() == HeroType::ENinja)
        {
            if (hero->getLoads() > 0)
            {
                unsigned int damage = hero->getWeapon().value()->getDamage();
                heroToAttack->takeDamage(damage);
                hero->setLoads(hero->getLoads() - 1);
            }
            else
            {
                return false;
            }
        }
        else if (hero->getType() == HeroType::ECatapult)
        {
            if (hero->getLoads() >= SIEGE_LOADS_NUMBER)
            {
                unsigned int damage = hero->getWeapon().value()->getDamage();
                heroToAttack->takeDamage(damage);
                hero->setLoads(0);
            }
            else
            {
                return false;
            }
        }
        else if (hero->getType() == HeroType::ETrebuchet)
        {
            if (hero->getLoads() >= SIEGE_LOADS_NUMBER)
            {
                unsigned int damage = hero->getWeapon().value()->getDamage();
                trebuchetSpecialAttack(actionField, damage);
                this->trebuchetAttackRepetition[actionField] = damage;
                hero->setLoads(0);
            }
            else
            {
                return false;
            }
        }
        else
        {
            heroToAttack->takeDamage(hero->getWeapon().value()->getDamage());
        }
        return true;
    }
    return false;
}

void GameController::mageSpecialAttack(std::shared_ptr<Hero> hero, std::shared_ptr<Hero> heroToAttack)
{
    heroToAttack->takeDamage(hero->getWeapon().value()->getDamage());
    auto opponentsHeroesFields = board->getFieldsWithHeroes();
    for (auto field : opponentsHeroesFields)
    {
        if (field->getHero().value()->getOwner() == heroToAttack->getOwner())
        {
            unsigned int secDamage = hero->getWeapon().value()->getSecondaryDamage();
            field->getHero().value()->takeDamage(secDamage);
        }
    }
}

void GameController::iceDruidSpecialAttack(std::shared_ptr<Hero> hero, std::shared_ptr<Hero> heroToAttack)
{
    heroToAttack->takeDamage(hero->getWeapon().value()->getDamage());
    frozenHeroes.push_back(heroToAttack);
}

void GameController::trebuchetSpecialAttack(std::shared_ptr<Field> actionField, unsigned int damage)
{
    auto opponentsHeroesFields = board->getFieldsAround(actionField);
    for (auto field : opponentsHeroesFields)
    {
        if (!field->isFree())
        {
            // Friendly Fire ON
            //  if (field->getHero().value()->getOwner() == actionField->getHero().value()->getOwner())
            //  {
            field->getHero().value()->takeDamage(damage);
            // }
        }
    }
    actionField->getHero().value()->takeDamage(damage);
}
// Actions end

// Other
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

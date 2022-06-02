#include "../../headers/gameplay/game_controller.hpp"
#include <iostream>
#include <cmath>

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

std::shared_ptr<Board> GameController::getBoard()
{
    return this->board;
}

// Jeżeli hero ma 100% życia nie powinno się go dać uleczyć
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
        unsigned int healPoints = hero->getWeapon().value()->getMedicalHealth();
        actionHero->heal(healPoints);
        std::cout << "Healed hero" << std::endl;

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

bool GameController::attackAction(std::shared_ptr<Field> heroField, std::shared_ptr<Field> actionField)
{
    if (actionField->getHero() == std::nullopt)
    {
        return false;
    }
    auto hero = heroField->getHero().value();
    auto heroToAttack = actionField->getHero().value();
    if (!actionField->isFree() && hero->getOwner() != heroToAttack->getOwner() && isFieldInRange(heroField, actionField, hero->getWeapon().value()->getRange())) // Pytanie czy Hero będzie miał weapon
    {
        if (hero->getWeapon() == std::nullopt)
        {
            return false;
        }
        if (hero->getType() == HeroType::EMage)
        {
            // Powinien móc zamrozić tylko jednego boahtera
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
                heroToAttack->takeDamage(hero->getWeapon().value()->getDamage());
                hero->setLoads(hero->getLoads() - 1);
            }
            else
            {
                return false;
            }
        }
        // else if (hero->getType() == HeroType::ECatapult)
        // {
        // }
        // else if (hero->getType() == HeroType::ETrebuchet)
        // {
        // }
        else
        {
            heroToAttack->takeDamage(hero->getWeapon().value()->getDamage());
        }

        std::cout << "Damage given" << std::endl;
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
            field->getHero().value()->takeDamage(hero->getWeapon().value()->getSecondaryDamage());
        }
    }
}

void GameController::iceDruidSpecialAttack(std::shared_ptr<Hero> hero, std::shared_ptr<Hero> heroToAttack)
{
    heroToAttack->takeDamage(hero->getWeapon().value()->getDamage());
    frozenHeroes.push_back(heroToAttack);
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

#include "../../../headers/game_logic/weapons/stone.hpp"

unsigned int Stone::getRange() const
{
    return this->range;
}

void Stone::setRange(unsigned int range)
{
    this->range = range;
}

unsigned int Stone::getDamage() const
{
    return this->damage;
}

void Stone::setDamage(unsigned int damage)
{
    this->damage = damage;
}

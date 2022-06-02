#include "../../../headers/game_logic/weapons/bow.hpp"

unsigned int Bow::getRange() const
{
    return this->range;
}

void Bow::setRange(unsigned int range)
{
    this->range = range;
}

unsigned int Bow::getDamage() const
{
    return this->damage;
}

void Bow::setDamage(unsigned int damage)
{
    this->damage = damage;
}

#include "../../../headers/game_logic/weapons/stone.hpp"

unsigned int Stone::getTotalPoints() const
{
    return this->total_points;
}

void Stone::setTotalPoints(unsigned int total_points)
{
    this->total_points = total_points;
}

unsigned int Stone::getRange() const
{
    return this->range;
}

void Stone::setRange(unsigned int range)
{
    if (this->total_points > range)
    {
        this->range = range;
        this->damage = this->total_points - range;
    }
}

unsigned int Stone::getDamage() const
{
    return this->damage;
}

void Stone::setDamage(unsigned int damage)
{
    if (this->total_points > damage)
    {
        this->damage = damage;
        this->range = this->total_points - damage;
    }
}






#include "bow.hpp"

unsigned int Bow::getTotalPoints() const
{
    return this->total_points;
}

void Bow::setTotalPoints(unsigned int total_points)
{
    this->total_points = total_points;
}

unsigned int Bow::getRange() const
{
    return this->range;
}

void Bow::setRange(unsigned int range)
{
    if (this->total_points > range)
    {
        this->range = range;
        this->damage = this->total_points - range;
    }
}

unsigned int Bow::getDamage() const
{
    return this->damage;
}

void Bow::setDamage(unsigned int damage)
{
    if (this->total_points > damage)
    {
        this->damage = damage;
        this->range = this->total_points - damage;
    }
}






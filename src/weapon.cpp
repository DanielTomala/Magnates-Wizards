#include "../headers/weapon.hpp"
#include <algorithm> //std::min

Weapon::Weapon()
{
    damage = 0;
    durability = 0;
    range = 0;
}

Weapon::Weapon(unsigned int damage, unsigned int durability, unsigned int range)
{
    this->damage = damage;
    this->durability = durability;
    this->range = range;
}

unsigned int Weapon::getDamage() const
{
    return damage;
}

unsigned int Weapon::getDurability() const
{
    return durability;
}

unsigned int Weapon::getRange() const
{
    return range;
}

void Weapon::setDamage(unsigned int damage)
{
    this->damage = damage;
}

void Weapon::setDurability(unsigned int durability)
{
    this->durability = durability;
}

void Weapon::setRange(unsigned int range)
{
    this->range = range;
}

void Weapon::takeDurabilityLoss(unsigned int durabilityPoints)
{
    int newDurability = durability - durabilityPoints;
    this->durability = std::max(newDurability, 0);
}

bool Weapon::isNotCrashed() const
{
    return durability > 0 ? true : false;
}
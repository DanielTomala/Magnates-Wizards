#include "wearable.hpp"
#include <algorithm> //std::max

Wearable::Wearable()
{
    protection = 0;
    durability = 0;
}

Wearable::Wearable(unsigned int protection, unsigned int durability)
{
    this->protection = protection;
    this->durability = durability;
}

unsigned int Wearable::getProtection() const
{
    return protection;
}

unsigned int Wearable::getDurability() const
{
    return durability;
}

void Wearable::setProtection(unsigned int protection)
{
    this->protection = protection;
}

void Wearable::setDurability(unsigned int durability)
{
    this->durability = durability;
}

void Wearable::takeDurabilityLoss(unsigned int durabilityPoints)
{
    int newDurability = durability - durabilityPoints;
    this->durability = std::max(newDurability, 0);
}

bool Wearable::isNotCrashed() const
{
    return durability > 0 ? true : false;
}
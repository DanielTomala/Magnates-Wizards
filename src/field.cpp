#include "field.hpp"

Field::Field(){}

Field::Field(bool isAvailable, bool isBoosted)
{
    this->isAvailable = isAvailable;
    this->isBoosted = isBoosted;
}

Field::Field(bool isAvailable, bool isBoosted, Hero hero)
{
    this->isAvailable = isAvailable;
    this->isBoosted = isBoosted;
    this->hero = hero;
}

bool Field::GetIsAvailable() const
{
    return this->isAvailable;
}

bool Field::GetIsBoosted() const
{
    return this->isBoosted;
}

std::optional<Hero> Field::GetHero() const
{
    return this->hero;
}

void Field::SetIsAvailable(bool isAvailable)
{
    if (isAvailable == true)
    {
        this->hero = NULL;
    }
    this->isAvailable = isAvailable;
}

void Field::SetIsBoosted(bool isBoosted)
{
    this->isBoosted = isBoosted;
}

void Field::SetHero(Hero hero)
{
    this->hero = hero;
}
#include "field.hpp"

Field::Field(){}

Field::Field(Hero hero, FieldBooster fieldBooster, BubbleBooster bubbleBooster)
{
    this->hero = hero;
    this->fieldBooster = fieldBooster;
    this->bubbleBooster = bubbleBooster;
}

bool Field::isFree() const
{
    return this->isFree;
}

bool Field::isBubbleBoosted() const
{
    return this->isBubbleBoosted;
}

bool Field::isFieldBoosted() const
{
    return this->isFieldBoosted;
}

std::optional<Hero> Field::getHero() const
{
    return this->hero;
}

std::optional<FieldBooster> Field::getFieldBooster() const
{
    return this->fieldBooster;
}

std::optional<BubbleBooster> Field::getBubbleBooster() const
{
    return this->bubbleBooster;
}

void Field::addHero(const & Hero hero)
{
    this->hero = hero;
    this->isFree = true;
}

void Field::addFieldBooster(const & FieldBooster fieldBooster)
{
    this->fieldBooster = fieldBooster; /* ewentualnie moze tez zmieniać isFieldBoosted na true */
}

void Field::addBubbleBooster(const & BubbleBooster bubbleBooster)
{
    this->bubbleBooster = bubbleBooster; /* no i tu tez */
}

void Field::removeHero()
{
    this->hero = nullptr;
    this->isFree = false;
}

void Field::removeFieldBooster()
{
    this->fieldBooster = nullptr;
}

void Field::removeBubbleBooster()
{
    this->bubbleBooster = nullptr;
}
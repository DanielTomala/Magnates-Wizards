#include "field.hpp"

Field::Field(){}

Field::Field(bool isFree, bool isBubbleBoosted, bool isFieldBoosted)
{
    this->isFree = isFree;
    this->isBubbleBoosted = isBoosted;
}

Field::Field(bool isFree, bool isBoosted, Hero hero, FieldBooster fieldBooster, BubbleBooster bubbleBooster)
{
    this->isFree = isFree;
    this->isBoosted = isBoosted;
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

void Field::setIsFree(bool isFree)
{
    if (isFree == true)
        this->hero = NULL;
    this->isFree = isFree;
}

void Field::setIsBubbleBoosted(bool isBubbleBoosted)
{
    if (this->isFieldBoosted == false)
        this->isBubbleBoosted = isBubbleBoosted;
}

void Field::setIsFieldBoosted(bool isFieldBoosted)
{
    if (this->isBubbleBoosted == false)
        this->isFieldBoosted = isFieldBoosted;
}

void Field::setHero(const & Hero hero)
{
    this->hero = hero;
}

void Field::setFieldBooster(const & FieldBooster fieldBooster)
{
    if (this->isFieldBoosted == true)
        this->fieldBooster = fieldBooster; /* ewentualnie moze tez zmieniać isFieldBoosted na true */
}

void Field::setBubbleBooster(const & BubbleBooster bubbleBooster)
{
    if (this->isBubbleBoosted == true)
        this->bubbleBooster = bubbleBooster; /* no i tu tez */
}
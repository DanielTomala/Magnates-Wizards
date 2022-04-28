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

bool Field::GetIsFree() const
{
    return this->isFree;
}

bool Field::GetIsBubbleBoosted() const
{
    return this->isBubbleBoosted;
}

bool Field::GetIsFieldBoosted() const
{
    return this->isFieldBoosted;
}

std::optional<Hero> Field::GetHero() const
{
    return this->hero;
}

std::optional<FieldBooster> Field::GetFieldBooster() const
{
    return this->fieldBooster;
}

std::optional<BubbleBooster> Field::GetBubbleBooster() const
{
    return this->bubbleBooster;
}

void Field::SetIsFree(bool isFree)
{
    if (isFree == true)
        this->hero = NULL;
    this->isFree = isFree;
}

void Field::SetIsBubbleBoosted(bool isBubbleBoosted)
{
    if (this->isFieldBoosted == false)
        this->isBubbleBoosted = isBubbleBoosted;
}

void Field::SetIsFieldBoosted(bool isFieldBoosted)
{
    if (this->isBubbleBoosted == false)
        this->isFieldBoosted = isFieldBoosted;
}

void Field::SetHero(Hero hero)
{
    this->hero = hero;
}

void Field::SetFieldBooster(FieldBooster fieldBooster)
{
    if (this->isFieldBoosted == true)
        this->fieldBooster = fieldBooster; /* ewentualnie moze tez zmieniać isFieldBoosted na true */
}

void Field::SetBubbleBooster(BubbleBooster bubbleBooster)
{
    if (this->isBubbleBoosted == true)
        this->bubbleBooster = bubbleBooster; /* no i tu tez */
}
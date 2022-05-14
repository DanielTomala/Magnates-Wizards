#include "../headers/field.hpp"

Field::Field() {
}

Field::Field(std::optional<Hero> hero, std::optional<FieldBooster> fieldBooster, std::optional<BubbleBooster> bubbleBooster){
    this->hero = hero;
    this->fieldBooster = fieldBooster;
    this->bubbleBooster = bubbleBooster;
}

bool Field::isFree() const
{
    return this->hero == std::nullopt ? true : false;
}

bool Field::isBubbleBoosted() const
{
    return this->bubbleBooster == std::nullopt ? true : false;
}

bool Field::isFieldBoosted() const
{
    return this->fieldBooster == std::nullopt ? true : false;
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

void Field::addHero(const Hero &hero)
{
    this->hero = hero;
}

void Field::addFieldBooster(const FieldBooster &fieldBooster)
{
    this->fieldBooster = fieldBooster;
}

void Field::addBubbleBooster(const BubbleBooster &bubbleBooster)
{
    this->bubbleBooster = bubbleBooster;
}

void Field::removeHero()
{
    this->hero = std::nullopt;
}

void Field::removeFieldBooster()
{
    this->fieldBooster = std::nullopt;
}

void Field::removeBubbleBooster()
{
    this->bubbleBooster = std::nullopt;
}

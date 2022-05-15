#include "../headers/field.hpp"
#include "../headers/bubble_booster.hpp"
#include "../headers/field_booster.hpp"
#include <optional>

Field::Field() {}

Field::Field(const Hero &hero, const FieldBooster &fieldBooster, const BubbleBooster &bubbleBooster)
{
    this->hero = std::make_optional<Hero &>(hero);
    this->fieldBooster = std::make_optional<FieldBooster &>(fieldBooster);
    this->bubbleBooster = std::make_optional<BubbleBooster &>(bubbleBooster);
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

std::optional<Hero &> Field::getHero() const
{
    return this->hero;
}

std::optional<FieldBooster &> Field::getFieldBooster() const
{
    return this->fieldBooster;
}

std::optional<BubbleBooster &> Field::getBubbleBooster() const
{
    return this->bubbleBooster;
}

void Field::addHero(const Hero &hero)
{
    this->hero = std::make_optional<Hero &>(hero);
}

void Field::addFieldBooster(const FieldBooster &fieldBooster)
{
    this->fieldBooster = std::make_optional<FieldBooster &>(fieldBooster);
}

void Field::addBubbleBooster(const BubbleBooster &bubbleBooster)
{
    this->bubbleBooster = std::make_optional<BubbleBooster &>(bubbleBooster);
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
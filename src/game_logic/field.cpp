#include "../../headers/game_logic/field.hpp"
#include "../../headers/game_logic/bubble_booster.hpp"
#include "../../headers/game_logic/field_booster.hpp"
#include <optional>

Field::Field() {
}

Field::Field(std::optional<std::shared_ptr<Hero> > hero, std::optional<FieldBooster> fieldBooster, std::optional<BubbleBooster> bubbleBooster){

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

 std::optional<std::shared_ptr<Hero> > Field::getHero() const
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

void Field::addHero(std::shared_ptr<Hero> hero)
{
    this->hero = std::make_optional<std::shared_ptr<Hero>>(hero);
}

void Field::addFieldBooster(FieldBooster fieldBooster)
{
    this->fieldBooster = std::make_optional<FieldBooster>(fieldBooster);
}

void Field::addBubbleBooster(BubbleBooster bubbleBooster)
{
    this->bubbleBooster = std::make_optional<BubbleBooster>(bubbleBooster);
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
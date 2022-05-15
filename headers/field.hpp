#ifndef FIELD_HPP
#define FIELD_HPP

#include "hero.hpp"
#include "field_booster.hpp"
#include "bubble_booster.hpp"

class Field
{
private:
    std::optional<Hero&> hero;
    std::optional<FieldBooster&> fieldBooster;
    std::optional<BubbleBooster&> bubbleBooster;

public:
    Field();
    Field(const Hero& hero, const FieldBooster& fieldBooster, const BubbleBooster& bubbleBooster);
    bool isFree() const;
    bool isBubbleBoosted() const;
    bool isFieldBoosted() const;
    std::optional<FieldBooster&> getFieldBooster() const;
    std::optional<BubbleBooster&> getBubbleBooster() const;
    std::optional<Hero&> getHero() const;

    void addHero(const Hero &hero);
    void addFieldBooster(const FieldBooster &fieldBooster);
    void addBubbleBooster(const BubbleBooster &bubbleBooster);

    void removeHero();
    void removeFieldBooster();
    void removeBubbleBooster();
};

#endif
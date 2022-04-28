#ifndef FIELD_HPP
#define FIELD_HPP

#include "hero.hpp"
#include "field_booster.hpp"
#include "bubble_booster.hpp"

class Field {
private:
    bool isFree;
    bool isBubbleBoosted;
    bool isFieldBoosted;
    std::optional<Hero> hero;
    std::optional<FieldBooster> fieldBooster;
    std::optional<BubbleBooster> bubbleBooster;
public:
    Field ();
    Field (bool isFree, bool isBubbleBoosted, bool isFieldBoosted);
    Field (bool isFree, bool isBubbleBoosted, bool isFieldBoosted, std::optional<Hero> hero, std::optional<FieldBooster> fieldBooster, std::optional<BubbleBooster> bubbleBooster);
    bool GetIsFree() const;
    bool GetIsBubbleBoosted() const;
    bool GetIsFieldBoosted() const;
    std::optional<FieldBooster> GetFieldBooster() const;
    std::optional<BubbleBooster> GetBubbleBooster() const;
    std::optional<Hero> GetHero() const;

    void SetIsFree(bool isFree);
    void SetIsBubbleBoosted(bool isBubbleBoosted);
    void SetIsFieldBoosted(bool isFieldBoosted);
    void SetHero(Hero hero);
    void SetFieldBooster(FieldBooster fieldBooster);
    void SetBubbleBooster(BubbleBooster bubbleBooster);
};

#endif
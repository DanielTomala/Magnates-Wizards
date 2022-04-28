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
    bool isFree() const;
    bool isBubbleBoosted() const;
    bool isFieldBoosted() const;
    std::optional<FieldBooster> getFieldBooster() const;
    std::optional<BubbleBooster> getBubbleBooster() const;
    std::optional<Hero> getHero() const;

    void setIsFree(bool isFree);
    void setIsBubbleBoosted(bool isBubbleBoosted);
    void setIsFieldBoosted(bool isFieldBoosted);
    void setHero(const & Hero hero);
    void setFieldBooster(const & FieldBooster fieldBooster);
    void setBubbleBooster(const & BubbleBooster bubbleBooster);
};

#endif
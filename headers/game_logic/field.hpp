#ifndef FIELD_HPP
#define FIELD_HPP

#include "./heroes/hero.hpp"
#include "./field_booster.hpp"
#include "./bubble_booster.hpp"
#include <SFML/Graphics.hpp>
#include <memory>
#include <optional>

class Field
{
private:
    std::optional<std::shared_ptr<Hero> > hero;
    std::optional<FieldBooster> fieldBooster;
    std::optional<BubbleBooster> bubbleBooster;
public:
    sf::Sprite sprite; //WILL BE PRIVATE


    Field();
    Field(std::optional<std::shared_ptr<Hero>> hero, std::optional<FieldBooster> fieldBooster, std::optional<BubbleBooster> bubbleBooster);
    bool isFree() const;
    bool isFieldBoosted() const;
    bool isBubbleBoosted() const;
    std::optional<FieldBooster> getFieldBooster() const;
    std::optional<BubbleBooster> getBubbleBooster() const;
    std::optional<std::shared_ptr<Hero> > getHero() const;

    void addHero(std::shared_ptr<Hero> hero);
    void addFieldBooster(FieldBooster fieldBooster);
    void addBubbleBooster(BubbleBooster bubbleBooster);

    void removeHero();
    void removeFieldBooster();
    void removeBubbleBooster();

};

#endif
#ifndef FIELD_HPP
#define FIELD_HPP

#include "hero.hpp"

class Field {
private:
    bool isAvailable;
    bool isBoosted;
    std::optional<Hero> hero;
public:
    bool GetIsAvailable() const;
    bool GetIsBoosted() const;
    std::optional<Hero> GetHero() const;

    void SetIsAvailable(bool isAvailable);
    void SetIsBoosted(bool isBoosted);
    void SetHero(Hero hero);
};

#endif
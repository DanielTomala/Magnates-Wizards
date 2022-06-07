#ifndef ARCHER_HPP
#define ARCHER_HPP

#include "./hero.hpp"

class Archer : public Hero
{
public:
    Archer() : Hero(){};
    Archer(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Archer(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Archer(){};
    HeroType getType() const override;
    void setAttributes() override;
};
#endif
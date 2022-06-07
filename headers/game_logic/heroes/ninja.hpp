#ifndef NINJA_HPP
#define NINJA_HPP

#include "./hero.hpp"

class Ninja : public Hero
{
public:
    Ninja() : Hero(){};
    Ninja(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Ninja(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Ninja(){};
    HeroType getType() const override;
    void setAttributes() override;
};
#endif
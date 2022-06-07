#ifndef MAGE_HPP
#define MAGE_HPP

#include "./hero.hpp"

class Mage : public Hero
{
public:
    Mage() : Hero(){};
    Mage(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Mage(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Mage(){};
    HeroType getType() const override;
    void setAttributes() override;
};

#endif
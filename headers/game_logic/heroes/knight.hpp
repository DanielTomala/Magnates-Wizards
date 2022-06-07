#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "./hero.hpp"

class Knight : public Hero
{
public:
    Knight() : Hero(){};
    Knight(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Knight(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Knight(){};
    HeroType getType() const override;
    void setAttributes() override;
};
#endif
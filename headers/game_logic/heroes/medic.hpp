#ifndef MEDIC_HPP
#define MEDIC_HPP

#include "./hero.hpp"

class Medic : public Hero
{
public:
    Medic() : Hero(){};
    Medic(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Medic(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Medic(){};
    HeroType getType() const override;
    void setAttributes() override;
};
#endif
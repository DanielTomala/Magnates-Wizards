#ifndef ICE_DRUID_HPP
#define ICE_DRUID_HPP

#include "./hero.hpp"

class IceDruid : public Hero
{
public:
    IceDruid() : Hero(){};
    IceDruid(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    IceDruid(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~IceDruid(){};
    HeroType getType() const override;
    void setAttributes() override;
};
#endif
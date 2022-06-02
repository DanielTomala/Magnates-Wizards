#ifndef STONE_HPP
#define STONE_HPP

#include "weapon.hpp"

class Stone : public Weapon
{
public:
    ~Stone(){};
    WeaponType getType() const override;
    unsigned int getSecondaryDamage() const { return 0; };
};

#endif
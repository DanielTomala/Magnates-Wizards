#ifndef SHURIKEN_HPP
#define SHURIKEN_HPP

#include "weapon.hpp"

class Shuriken : public Weapon
{
public:
    ~Shuriken(){};
    WeaponType getType() const override;
    unsigned int getSecondaryDamage() const { return 0; };
    unsigned int getHealPoints() const { return 0; };
};

#endif
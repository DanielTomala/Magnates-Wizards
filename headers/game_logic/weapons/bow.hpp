#ifndef BOW_HPP
#define BOW_HPP

#include "weapon.hpp"

class Bow : public Weapon
{
public:
    ~Bow(){};
    WeaponType getType() const override;
    unsigned int getSecondaryDamage() const { return 0; };
    unsigned int getHealPoints() const { return 0; };
};

#endif
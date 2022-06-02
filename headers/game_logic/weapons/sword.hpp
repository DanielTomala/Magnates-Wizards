#ifndef SWORD_HPP
#define SWORD_HPP

#include "weapon.hpp"

class Sword : public Weapon
{
public:
    ~Sword(){};
    WeaponType getType() const override;
    unsigned int getSecondaryDamage() const { return 0; };
    unsigned int getMedicalHealth() const { return 0; };
};

#endif
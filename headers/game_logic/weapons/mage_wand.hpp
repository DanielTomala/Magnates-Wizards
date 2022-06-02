#ifndef MAGE_WAND_HPP
#define MAGE_WAND_HPP

#include "weapon.hpp"

class MageWand : public Weapon
{
public:
    unsigned int getSecondaryDamage() const override;
    WeaponType getType() const override;
    unsigned int getMedicalHealth() const { return 0; };
};

#endif
#include "../../../headers/game_logic/weapons/mage_wand.hpp"

unsigned int MageWand::getSecondaryDamage() const
{
    return 0.1 * getDamage();
}
WeaponType MageWand::getType() const
{
    return WeaponType::EMagicWand;
}
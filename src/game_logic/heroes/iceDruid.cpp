#include "../../../headers/game_logic/heroes/iceDruid.hpp"

HeroType IceDruid::getType() const
{
    return EIceDruid;
}

void IceDruid::setAttributes()
{
    IceDruidStaff staff;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EIceDruid, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EIceDruid, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EIceDruid, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EIceDruid, Balanced));
        break;
    }
    staff.setDamage(attributes.weaponDamage);
    staff.setRange(attributes.weaponRange);
    staff.setDurability(attributes.weaponDurability);
    this->addWeapon(std::make_shared<IceDruidStaff>(staff));

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}
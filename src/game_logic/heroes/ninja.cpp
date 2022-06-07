#include "../../../headers/game_logic/heroes/ninja.hpp"

HeroType Ninja::getType() const
{
    return ENinja;
}



void Ninja::setAttributes()
{
    Shuriken shuriken;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(ENinja, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(ENinja, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(ENinja, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(ENinja, Balanced));
        break;
    }
    shuriken.setDamage(attributes.weaponDamage);
    shuriken.setRange(attributes.weaponRange);
    shuriken.setDurability(attributes.weaponDurability);
    this->addWeapon(std::make_shared<Shuriken>(shuriken));

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}
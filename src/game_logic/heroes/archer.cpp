#include "../../../headers/game_logic/heroes/archer.hpp"

HeroType Archer::getType() const
{
    return EArcher;
}

void Archer::setAttributes()
{
    Bow bow;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EArcher, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EArcher, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EArcher, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EArcher, Balanced));
        break;
    }
    bow.setDamage(attributes.weaponDamage);
    bow.setRange(attributes.weaponRange);
    bow.setDurability(attributes.weaponDurability);
    this->addWeapon(std::make_shared<Bow>(bow));
    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}
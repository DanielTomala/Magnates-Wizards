#include "../../../headers/game_logic/heroes/catapult.hpp"

HeroType Catapult::getType() const
{
    return ECatapult;
}

void Catapult::setAttributes()
{
    Stone stone;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(ECatapult, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(ECatapult, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(ECatapult, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(ECatapult, Balanced));
        break;
    }
    stone.setDamage(attributes.weaponDamage);
    stone.setRange(attributes.weaponRange);
    stone.setDurability(attributes.weaponDurability);
    this->addWeapon(std::make_shared<Stone>(stone));

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}
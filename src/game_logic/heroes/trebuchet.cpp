#include "../../../headers/game_logic/heroes/trebuchet.hpp"

HeroType Trebuchet::getType() const
{
    return ETrebuchet;
}

void Trebuchet::setAttributes()
{
    Stone stone;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(ETrebuchet, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(ETrebuchet, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(ETrebuchet, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(ETrebuchet, Balanced));
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

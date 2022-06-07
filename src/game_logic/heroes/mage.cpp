#include "../../../headers/game_logic/heroes/mage.hpp"

HeroType Mage::getType() const
{
    return EMage;
}

void Mage::setAttributes()
{
    MageWand wand;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EMage, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EMage, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EMage, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EMage, Balanced));
        break;
    }
    wand.setDamage(attributes.weaponDamage);
    wand.setRange(attributes.weaponRange);
    wand.setDurability(attributes.weaponDurability);
    this->addWeapon(std::make_shared<MageWand>(wand));

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

#include "../../../headers/game_logic/heroes/knight.hpp"

HeroType Knight::getType() const
{
    return EKnight;
}

void Knight::setAttributes()
{
    Sword sword;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EKnight, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EKnight, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EKnight, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EKnight, Balanced));
        break;
    }
    sword.setDamage(attributes.weaponDamage);
    sword.setRange(attributes.weaponRange);
    sword.setDurability(attributes.weaponDurability);
    this->addWeapon(std::make_shared<Sword>(sword));

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

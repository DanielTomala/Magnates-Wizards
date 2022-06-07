#include "../../../headers/game_logic/heroes/medic.hpp"

HeroType Medic::getType() const
{
    return EMedic;
}

void Medic::setAttributes()
{
    MedicalBox medicalBox;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EMedic, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EMedic, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EMedic, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EMedic, Balanced));
        break;
    }
    medicalBox.setDamage(attributes.weaponDamage);
    medicalBox.setRange(attributes.weaponRange);
    medicalBox.setDurability(attributes.weaponDurability);
    medicalBox.setMedicalHealth(attributes.healing);

    this->addWeapon(std::make_shared<MedicalBox>(medicalBox));
    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

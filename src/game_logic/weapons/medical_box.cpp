#include "../../../headers/game_logic/weapons/medical_box.hpp"

unsigned int MedicalBox::getMedicalHealth() const
{
    return this->medical_health;
}

void MedicalBox::setMedicalHealth(unsigned int medical_health)
{
    this->medical_health = medical_health;
}

void MedicalBox::subtractMedicalHealth(unsigned int points_of_health)
{
    this->medical_health -= points_of_health;
}

WeaponType MedicalBox::getType() const
{
    return WeaponType::EMedicalBox;
}
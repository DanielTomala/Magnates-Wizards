#ifndef MEDICAL_BOX_HPP
#define MEDICAL_BOX_HPP

#include "weapon.hpp"

class MedicalBox : public Weapon
{
protected:
    unsigned int medical_health;

public:
    ~MedicalBox(){};
    unsigned int getMedicalHealth() const override;
    void setMedicalHealth(unsigned int medical_health);
    void subtractMedicalHealth(unsigned int points_of_health);
    WeaponType getType() const override;
    unsigned int getSecondaryDamage() const { return 0; };
};

#endif
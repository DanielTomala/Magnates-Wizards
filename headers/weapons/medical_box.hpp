#ifndef MAGE_WAND_HPP
#define MAGE_WAND_HPP

#include "weapon.hpp"

class MedicalBox : public Weapon
{
protected:
    unsigned int medical_health;
public:
    unsigned int getMedicalHealth() const;
    void setMedicalHealth(unsigned int medical_health);
    void subtractMedicalHealth(unsigned int points_of_health);
};

#endif
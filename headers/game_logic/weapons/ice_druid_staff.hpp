#ifndef ICE_DRUID_STAFF_HPP
#define ICE_DRUID_STAFF_HPP

#include "weapon.hpp"

class IceDruidStaff : public Weapon
{
private:
    unsigned int locked_fields;
    unsigned int freeze_time;

public:
    ~IceDruidStaff(){};
    unsigned int getLockedFields() const;
    void setLockedFields(unsigned int locked_fields);
    unsigned int getFreezeTime() const;
    void setFreezeTime(unsigned int freeze_time);
    WeaponType getType() const override;
    unsigned int getSecondaryDamage() const { return 0; };
};

#endif
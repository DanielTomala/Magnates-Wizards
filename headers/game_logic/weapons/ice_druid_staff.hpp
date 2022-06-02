#ifndef ICE_DRUID_STAFF_HPP
#define ICE_DRUID_STAFF_HPP

#include "weapon.hpp"

class IceDruidStaff : public Weapon
{
protected:
    unsigned int locked_fields;
    unsigned int freeze_time;
public:
    unsigned int getLockedFields() const;
    void setLockedFields(unsigned int locked_fields);
    unsigned int getFreezeTime() const;
    void setFreezeTime(unsigned int freeze_time);
};

#endif
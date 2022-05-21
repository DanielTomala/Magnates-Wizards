#ifndef ICE_DRUID_STAFF_HPP
#define ICE_DRUID_STAFF_HPP

#include "weapon.hpp"

class IceDruidStaff : public Weapon
{
protected:
    unsigned int total_points;
    unsigned int locked_fields;
    unsigned int freeze_time;
public:
    unsigned int getTotalPoints() const;
    void setTotalPoints(unsigned int total_points);
    unsigned int getLockedFields() const;
    void setLockedFields(unsigned int locked_fields);
    unsigned int getFreezeTime() const;
    void setFreezeTime(unsigned int freeze_time);
};

#endif
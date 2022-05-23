#ifndef GROUND_DRUID_STAFF_HPP
#define GROUND_DRUID_STAFF_HPP

#include "weapon.hpp"

class GroundDruidStaff : public Weapon
{
protected:
    unsigned int total_points;
    unsigned int locked_fields;
    unsigned int range;
public:
    unsigned int getTotalPoints() const;
    void setTotalPoints(unsigned int total_points);
    unsigned int getLockedFields() const;
    void setLockedFields(unsigned int locked_fields);
    unsigned int getRange() const;
    void setRange(unsigned int range);
};

#endif
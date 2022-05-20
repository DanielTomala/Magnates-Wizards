#include "ground_druid_staff.hpp"

unsigned int GroundDruidStaff::getTotalPoints() const
{
    return this->total_points;
}

void GroundDruidStaff::setTotalPoints(unsigned int total_points)
{
    this->total_points = total_points;
}

unsigned int GroundDruidStaff::getLockedFields() const
{
    return this->locked_fields;
}

void GroundDruidStaff::setLockedFields(unsigned int locked_fields)
{
    if (this->total_points > locked_fields)
    {
        this->locked_fields = locked_fields;
        this->range = this->total_points - locked_fields;
    }
}

unsigned int GroundDruidStaff::getRange() const
{
    return this->range;
}

void GroundDruidStaff::setRange(unsigned int range)
{
    if (this->total_points > range)
    {
        this->range = range;
        this->locked_fields = this->locked_fields - range;
    }  
}





#include "../../../headers/game_logic/weapons/ice_druid_staff.hpp"

unsigned int IceDruidStaff::getTotalPoints() const
{
    return this->total_points;
}

void IceDruidStaff::setTotalPoints(unsigned int total_points)
{
    this->total_points = total_points;
}

unsigned int IceDruidStaff::getLockedFields() const
{
    return this->locked_fields;
}

void IceDruidStaff::setLockedFields(unsigned int locked_fields)
{
    if (this->total_points > locked_fields)
    {
        this->locked_fields = locked_fields;
        this->freeze_time = this->total_points - locked_fields;
    }
}

unsigned int IceDruidStaff::getFreezeTime() const
{
    return this->freeze_time;
}

void IceDruidStaff::setFreezeTime(unsigned int freeze_time)
{
    if (this->total_points > freeze_time)
    {
        this->freeze_time = freeze_time;
        this->locked_fields = this->total_points - freeze_time;
    }
}






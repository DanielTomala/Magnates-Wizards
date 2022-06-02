#include "../../../headers/game_logic/weapons/ice_druid_staff.hpp"

unsigned int IceDruidStaff::getLockedFields() const
{
    return this->locked_fields;
}

void IceDruidStaff::setLockedFields(unsigned int locked_fields)
{
    this->locked_fields = locked_fields;
}

unsigned int IceDruidStaff::getFreezeTime() const
{
    return this->freeze_time;
}

void IceDruidStaff::setFreezeTime(unsigned int freeze_time)
{
    this->freeze_time = freeze_time;
}

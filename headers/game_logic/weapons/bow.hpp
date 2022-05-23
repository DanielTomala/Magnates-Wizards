#ifndef BOW_HPP
#define BOW_HPP

#include "weapon.hpp"

class Bow : public Weapon
{
protected:
    unsigned int total_points;
    unsigned int range;
    unsigned int damage;
public:
    unsigned int getTotalPoints() const;
    void setTotalPoints(unsigned int total_points);
    unsigned int getRange() const;
    void setRange(unsigned int range);
    unsigned int getDamage() const;
    void setDamage(unsigned int damage);
};

#endif
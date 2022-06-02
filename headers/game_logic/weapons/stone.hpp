#ifndef STONE_HPP
#define STONE_HPP

#include "weapon.hpp"

class Stone : public Weapon
{
protected:
    unsigned int range;
    unsigned int damage;
public:
    unsigned int getRange() const;
    void setRange(unsigned int range);
    unsigned int getDamage() const;
    void setDamage(unsigned int damage);
};

#endif
#ifndef HERO_HPP
#define HERO

#include "weapon.hpp"
#include "wearable.hpp"

class Hero
{
public:
    unsigned int getMaxHealth() const;
    unsigned int getCurrentHealth() const;
    Weapon getWeapon() const;
    Wearable getWearable() const;

    void setMaxHealth(unsigned int health) ;
    void setCurrentHealth(unsigned int health);
    void setWeapon(Weapon weapon);
    void setWearable(Wearable wearable);

    void heal(unsigned int healHealth);
    void takeDamage(unsigned int damage);

    bool isAlive() const;

private:
    unsigned int maxHealth;
    unsigned int currentHealth;
    Weapon weapon;
    Wearable wearable;
};

#endif
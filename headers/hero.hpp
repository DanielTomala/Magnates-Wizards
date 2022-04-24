#ifndef HERO_HPP
#define HERO

#include "weapon.hpp"
#include "wearable.hpp"

#include <optional>

class Hero
{
public:
    Hero();
    Hero(unsigned int maxHealth);
    Hero(unsigned int maxHealth, Weapon weapon, Wearable wearable);

    unsigned int getMaxHealth() const;
    unsigned int getCurrentHealth() const;
    std::optional<Weapon> getWeapon() const;
    std::optional<Wearable> getWearable() const;

    void setMaxHealth(unsigned int health);
    void setCurrentHealth(unsigned int health);
    void setWeapon(Weapon weapon);
    void setWearable(Wearable wearable);

    void heal(unsigned int healHealth);
    void takeDamage(unsigned int damage);

    bool isAlive() const;

private:
    unsigned int maxHealth;
    unsigned int currentHealth;
    std::optional<Weapon> weapon;
    std::optional<Wearable> wearable;
};

#endif
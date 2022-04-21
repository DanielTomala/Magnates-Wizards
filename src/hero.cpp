#include "hero.hpp"
#include <algorithm> //std::min

unsigned int Hero::getMaxHealth() const
{
    return maxHealth;
}

unsigned int Hero::getCurrentHealth() const
{
    return currentHealth;
}

Weapon Hero::getWeapon() const
{
    return weapon;
}

Wearable Hero::getWearable() const
{
    return wearable;
}

void Hero::setCurrentHealth(unsigned int health)
{
    this->maxHealth = health;
}

void Hero::setCurrentHealth(unsigned int health)
{
    this->currentHealth = health;
}

void Hero::setWeapon(Weapon weapon)
{
    this->weapon = weapon;
}

void Hero::setWearable(Wearable wearable)
{
    this->wearable = wearable;
}

void Hero::heal(unsigned int healHealth)
{
    this->currentHealth = std::min(currentHealth + healHealth, maxHealth);
}

void Hero::takeDamage(unsigned int damage)
{
    int newCurrentHealt = currentHealth - damage;
    this->currentHealth = std::max(newCurrentHealt, 0);
}

bool Hero::isAlive() const
{
    return currentHealth > 0 ? true : false;
}
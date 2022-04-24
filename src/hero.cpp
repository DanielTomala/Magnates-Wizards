#include "hero.hpp"
#include <algorithm> //std::min
#include <optional>  //std::optional

Hero::Hero()
{
    this->maxHealth = 0;
    this->currentHealth = 0;
}

Hero::Hero(unsigned int maxHealth)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
}

Hero::Hero(unsigned int maxHealth, Weapon weapon, Wearable wearable)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->weapon = weapon;
    this->wearable = wearable;
}

unsigned int Hero::getMaxHealth() const
{
    return maxHealth;
}

unsigned int Hero::getCurrentHealth() const
{
    return currentHealth;
}

std::optional<Weapon> Hero::getWeapon() const
{
    return weapon;
}

std::optional<Wearable> Hero::getWearable() const
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
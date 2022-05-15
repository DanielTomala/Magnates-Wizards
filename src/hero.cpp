#include "../headers/hero.hpp"
#include "../headers/consts.hpp"
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

Hero::Hero(unsigned int maxHealth, const Weapon &weapon, const Wearable &wearable)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->weapon = std::make_optional<Weapon &>(weapon);
    this->wearable = std::make_optional<Wearable &>(wearable);
}

unsigned int Hero::getMaxHealth() const
{
    return maxHealth;
}

unsigned int Hero::getCurrentHealth() const
{
    return currentHealth;
}

std::optional<Weapon &> Hero::getWeapon() const
{
    return weapon;
}

std::optional<Wearable &> Hero::getWearable() const
{
    return wearable;
}

void Hero::setMaxHealth(unsigned int health)
{
    this->maxHealth = health;
}

void Hero::setCurrentHealth(unsigned int health)
{
    this->currentHealth = health;
}

void Hero::addWeapon(const Weapon &weapon)
{
    this->weapon = std::make_optional<Weapon &>(weapon);
}

void Hero::addWearable(const Wearable &wearable)
{
    this->wearable = std::make_optional<Wearable &>(wearable);
}

void Hero::removeWeapon()
{
    this->weapon = std::nullopt;
}

void Hero::removeWearable()
{
    this->wearable = std::nullopt;
}

// Hero cannot be healed if his health already dropped to 0
void Hero::heal(unsigned int healHealth)
{
    if (getCurrentHealth() > 0)
    {
        this->currentHealth = std::min(currentHealth + healHealth, maxHealth);
    }
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

HeroType Hero::getType()
{
    return HeroType::EHero;
}
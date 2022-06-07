#include "../../../headers/game_logic/heroes/hero.hpp"

#include <iostream>
#include <memory>

Hero::~Hero() {}

// Constructors
Hero::Hero()
{
    this->maxHealth = 0;
    this->currentHealth = 0;
    this->personalisation = Balanced;
    this->loads = 0;
}

Hero::Hero(unsigned int maxHealth, unsigned int moveRange)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->moveRange = moveRange;
    this->loads = 0;
}

Hero::Hero(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->moveRange = moveRange;
    this->loads = 0;
    this->weapon = std::make_optional<std::shared_ptr<Weapon>>(weapon);
    this->wearable = std::make_optional<std::shared_ptr<Wearable>>(wearable);
}
// Constructors end

// Getters
unsigned int Hero::getMaxHealth() const
{
    return maxHealth;
}

unsigned int Hero::getCurrentHealth() const
{
    return currentHealth;
}

unsigned int Hero::getMoveRange() const
{
    return moveRange;
}

Personalisation Hero::getPersonalisation() const
{
    return this->personalisation;
}

unsigned int Hero::getLoads() const
{
    return loads;
}

Player Hero::getOwner() const
{
    return this->owner;
}

std::optional<std::shared_ptr<Weapon>> Hero::getWeapon() const
{
    return weapon;
}

std::optional<std::shared_ptr<Wearable>> Hero::getWearable() const
{
    return wearable;
}
// Getters end

// Setters
void Hero::setMaxHealth(unsigned int health)
{
    this->maxHealth = health;
}

void Hero::setCurrentHealth(unsigned int health)
{
    this->currentHealth = health;
}

void Hero::setMoveRange(unsigned int range)
{
    this->moveRange = range;
}

void Hero::setPersonalisation(const Personalisation &personalisation)
{
    this->personalisation = personalisation;
}

void Hero::setLoads(unsigned int loads)
{
    this->loads = loads;
}

void Hero::setOwner(Player owner)
{
    this->owner = owner;
}
// Setters end

void Hero::addWeapon(std::shared_ptr<Weapon> weapon)
{
    this->weapon = std::make_optional<std::shared_ptr<Weapon>>(weapon);
}

void Hero::addWearable(std::shared_ptr<Wearable> wearable)
{
    this->wearable = std::make_optional<std::shared_ptr<Wearable>>(wearable);
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
// Hero cannot be healed if his health is already max
void Hero::heal(unsigned int healHealth)
{
    if (getCurrentHealth() > 0 && getCurrentHealth() < getMaxHealth())
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
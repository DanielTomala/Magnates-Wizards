#ifndef HERO_HPP
#define HERO_HPP

#include "../weapons/weapon.hpp"
#include "../wearable.hpp"
#include <algorithm> //std::min
#include <optional>  //std::optional
#include <SFML/Graphics.hpp>
#include "hero_attributes.hpp"
#include <memory>

#include "../weapons/bow.hpp"
#include "../weapons/ice_druid_staff.hpp"
#include "../weapons/mage_wand.hpp"
#include "../weapons/medical_box.hpp"
#include "../weapons/shuriken.hpp"
#include "../weapons/sword.hpp"
#include "../weapons/stone.hpp"

enum Player
{
    First,
    Second
};

class Hero
{
public:
    Hero();
    virtual ~Hero();
    Hero(unsigned int maxHealth, unsigned int moveRange);
    Hero(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable);

    unsigned int getMaxHealth() const;
    unsigned int getCurrentHealth() const;
    unsigned int getMoveRange() const;
    Personalisation getPersonalisation() const;
    unsigned int getLoads() const;

    std::optional<std::shared_ptr<Weapon>> getWeapon() const;
    std::optional<std::shared_ptr<Wearable>> getWearable() const;

    void setMaxHealth(unsigned int health);
    void setCurrentHealth(unsigned int health);
    void setLoads(unsigned int loads);

    void addWeapon(std::shared_ptr<Weapon> weapon);
    void addWearable(std::shared_ptr<Wearable> wearable);

    void removeWeapon();
    void removeWearable();

    void heal(unsigned int healHealth);
    void takeDamage(unsigned int damage);

    bool isAlive() const;
    sf::Sprite sprite;

    virtual HeroType getType() const = 0;
    virtual void setAttributes() = 0;

    void setPersonalisation(const Personalisation &personalisation);
    void setMoveRange(unsigned int range);

    void setOwner(Player owner);
    Player getOwner() const;

protected:
    unsigned int moveRange;
    unsigned int maxHealth;
    unsigned int currentHealth;
    unsigned int loads;
    std::optional<std::shared_ptr<Weapon>> weapon;
    std::optional<std::shared_ptr<Wearable>> wearable;
    Player owner;
    Personalisation personalisation;
};
#endif

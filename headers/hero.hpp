#ifndef HERO_HPP
#define HERO_HPP

#include "./weapons/weapon.hpp"
#include "wearable.hpp"
#include <algorithm> //std::min
#include <optional>  //std::optional
#include <SFML/Graphics.hpp>

enum HeroType
{
    EHero,
    EArcher,
    EKnight,
    EMage,
    EIceDruid,
    EGroundDruid,
    ECatapult,
    EMedic,
    ENinja,
    ETrebuchet
};

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
    Hero(unsigned int maxHealth);
    Hero(unsigned int maxHealth, const Weapon& weapon, const Wearable& wearable);

    unsigned int getMaxHealth() const;
    unsigned int getCurrentHealth() const;
    std::optional<Weapon&> getWeapon() const;
    std::optional<Wearable&> getWearable() const;

    void setMaxHealth(unsigned int health);
    void setCurrentHealth(unsigned int health);

    void addWeapon(const Weapon &weapon);
    void addWearable(const Wearable &wearable);

    void removeWeapon();
    void removeWearable();

    void heal(unsigned int healHealth);
    void takeDamage(unsigned int damage);

    bool isAlive() const;
    sf::Sprite sprite;  // WILL BE PRIVATE
    
    virtual HeroType getType();


    void setOwner(Player owner);
    Player getOwner() const;
private:
    unsigned int maxHealth;
    unsigned int currentHealth;
    std::optional<Weapon> weapon;
    std::optional<Wearable> wearable;
    Player owner;
};

class Knight: public Hero{
    public:
        virtual ~Knight();
        HeroType getType();
};
#endif

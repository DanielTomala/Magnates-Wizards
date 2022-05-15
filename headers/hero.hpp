#ifndef HERO_HPP
#define HERO_HPP

#include "weapon.hpp"
#include "wearable.hpp"
#include "consts.hpp"

#include <optional>

class Hero
{
public:
    Hero();
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

    //Każda klasa dziedzicząca powinna zwracać odpowiedni enum w zależności od typu klasy
    virtual HeroType getType();

private:
    unsigned int maxHealth;
    unsigned int currentHealth;
    std::optional<Weapon&> weapon;
    std::optional<Wearable&> wearable;
};

#endif

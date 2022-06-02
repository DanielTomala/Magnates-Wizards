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

    std::optional<std::shared_ptr<Weapon>> getWeapon() const;
    std::optional<std::shared_ptr<Wearable>> getWearable() const;

    void setMaxHealth(unsigned int health);
    void setCurrentHealth(unsigned int health);

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
    std::optional<std::shared_ptr<Weapon>> weapon;
    std::optional<std::shared_ptr<Wearable>> wearable;
    Player owner;
    Personalisation personalisation;
};

class Archer : public Hero
{
public:
    Archer(){};
    Archer(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Archer(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Archer(){};
    HeroType getType() const override;
    void setAttributes() override;
    // jak dodać restrykcję co do Weapon?
};

class Knight : public Hero
{
public:
    Knight() : Hero(){};
    Knight(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Knight(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Knight(){};
    HeroType getType() const override;
    void setAttributes() override;
};

class Mage : public Hero
{
public:
    Mage() : Hero(){};
    Mage(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Mage(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Mage(){};
    HeroType getType() const override;
    void setAttributes() override;
};

class IceDruid : public Hero
{
public:
    IceDruid() : Hero(){};
    IceDruid(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    IceDruid(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~IceDruid(){};
    HeroType getType() const override;
    void setAttributes() override;
    // zamraza Hero na cala nastepna runde, dodatkowo zadaje dmg

    // wektor zamrozonych, sprzwdzamy podczas akcji czy postać w wektorze
};

class Medic : public Hero
{
public:
    Medic() : Hero(){};
    Medic(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Medic(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Medic(){};
    HeroType getType() const override;
    void setAttributes() override;
};

class Ninja : public Hero
{
public:
    Ninja() : Hero(){};
    Ninja(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Ninja(unsigned int maxHealth, unsigned int moveRange, std::shared_ptr<Weapon> weapon, std::shared_ptr<Wearable> wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Ninja(){};
    HeroType getType() const override;
    void setAttributes() override;

private:
    unsigned int attacksLeft; // zmniejsza sie po ataku, jak == 0 nie moze atakowac

    // moze co 2 pola sie ruszac, może zaatakować dwa cele
};

class Catapult : public Hero
{
public:
    Catapult() : Hero(){};
    Catapult(unsigned int maxHealth) : Hero(maxHealth, 0){};
    virtual ~Catapult(){};
    HeroType getType() const override;
    void setAttributes() override;

private:
    unsigned int reloadTurnsLeft; //
    // duzy range
    // nie zmienia połozenia, musi sie ladowac, moze strzelac co x tur, zadaje duże obrażenia jednorazowo na danym polu
};

class Trebuchet : public Hero
{
public:
    Trebuchet() : Hero(){};
    Trebuchet(unsigned int maxHealth) : Hero(maxHealth, 0){};
    virtual ~Trebuchet(){};
    HeroType getType() const override;
    void setAttributes() override;

private:
    unsigned int reloadTurnsLeft; //

    // zadaje dmg na kwadracie dookoła atakowanego zawodnika
    // Zadaje niewielkie obrażenia na pewnym obszarze, stoi w jednym miejscu,
};

#endif

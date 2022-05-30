#ifndef HERO_HPP
#define HERO_HPP

#include "../weapons/weapon.hpp"
#include "../wearable.hpp"
#include <algorithm> //std::min
#include <optional>  //std::optional
#include <SFML/Graphics.hpp>

enum HeroType
{
    EArcher,
    EKnight,
    EWizard,
    EIceDruid,
    ECatapult,
    EMedic,
    ENinja,
    ETrebuchet
};


enum Parameters{ // AttackRange/Damage
    LowHigh,
    MediumMedium,
    HighLow
};

enum Player
{
    First,
    Second
};

enum Personalisation{
    Damage,
    Balanced,
    Range
};

class Hero
{
public:
    Hero();
    virtual ~Hero();
    Hero(unsigned int maxHealth, unsigned int moveRange);
    Hero(unsigned int maxHealth, unsigned int moveRange, const Weapon weapon, const Wearable wearable);

    unsigned int getMaxHealth() const;
    unsigned int getCurrentHealth() const;
    unsigned int getMoveRange() const;

    std::optional<Weapon> getWeapon() const;
    std::optional<Wearable> getWearable() const;

    void setMaxHealth(unsigned int health);
    void setCurrentHealth(unsigned int health);

    void addWeapon(const Weapon weapon);
    void addWearable(const Wearable wearable);

    void removeWeapon();
    void removeWearable();

    void heal(unsigned int healHealth);
    void takeDamage(unsigned int damage);

    bool isAlive() const;
    sf::Sprite sprite;

    virtual HeroType getType() = 0;
    virtual void setAttributes(Personalisation personalisation) = 0;

    void setOwner(Player owner);
    Player getOwner() const;

private:
    unsigned int moveRange;
    unsigned int maxHealth;
    unsigned int currentHealth;
    std::optional<Weapon> weapon;
    std::optional<Wearable> wearable;
    Player owner;
};

class Archer : public Hero
{
public:
    Archer(){};
    Archer(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Archer(unsigned int maxHealth, unsigned int moveRange, Weapon weapon, Wearable wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Archer(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
    // jak dodać restrykcję co do Weapon?
};

class Knight : public Hero
{
public:
    Knight() : Hero(){};
    Knight(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Knight(unsigned int maxHealth, unsigned int moveRange, Weapon weapon, Wearable wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Knight(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
};

class Mage : public Hero
{
public:
    Mage() : Hero(){};
    Mage(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Mage(unsigned int maxHealth, unsigned int moveRange, Weapon weapon, Wearable wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Mage(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
    // jak dodać restrykcję co do Weapon?

    // funckja zadawania dmg przechodzącego przez kilka wrogów z pomniejszeniem wartości dmg

    // glowny w range i wszyscy pozostali przeciwnika dostaja dmg 
};

class IceDruid : public Hero
{
public:
    IceDruid() : Hero(){};
    IceDruid(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    IceDruid(unsigned int maxHealth, unsigned int moveRange, Weapon weapon, Wearable wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~IceDruid(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
    // jak dodać restrykcję co do Weapon?

    // zamraza Hero na cala nastepna runde, dodatkowo zadaje dmg

    // wektor zamrozonych, sprzwdzamy podczas akcji czy postać w wektorze
};

class Medic : public Hero
{
public:
    Medic() : Hero(){};
    Medic(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Medic(unsigned int maxHealth, unsigned int moveRange, Weapon weapon, Wearable wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Medic(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
    // jak dodać restrykcję co do Weapon?

    // leczenie innych heroes, nie zadaje dmg, wybór pomiędzy zasięgiem a stopniem leczenia (może uleczyć dużo blisko albo mało daleko)
};

class Ninja : public Hero
{
public:
    Ninja() : Hero(){};
    Ninja(unsigned int maxHealth, unsigned int moveRange) : Hero(maxHealth, moveRange){};
    Ninja(unsigned int maxHealth, unsigned int moveRange, Weapon weapon, Wearable wearable) : Hero(maxHealth, moveRange, weapon, wearable){};
    virtual ~Ninja(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
private:
    unsigned int attacksLeft; //zmniejsza sie po ataku, jak == 0 nie moze atakowac
    // jak dodać restrykcję co do Weapon?

    // moze co 2 pola sie ruszac, może zaatakować dwa cele
};

class Catapult : public Hero
{
public:
    Catapult() : Hero(){};
    Catapult(unsigned int maxHealth) : Hero(maxHealth, 0){};
    virtual ~Catapult(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation); 

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
    HeroType getType();
    void setAttributes(Personalisation personalisation);

private:
    unsigned int reloadTurnsLeft; // 

    // zadaje dmg na kwadracie dookoła atakowanego zawodnika
    // Zadaje niewielkie obrażenia na pewnym obszarze, stoi w jednym miejscu,
};

#endif

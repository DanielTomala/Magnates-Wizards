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
    Hero(unsigned int maxHealth);
    Hero(unsigned int maxHealth, const Weapon weapon, const Wearable wearable);

    unsigned int getMaxHealth() const;
    unsigned int getCurrentHealth() const;
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
    sf::Sprite sprite; // WILL BE PRIVATE

    virtual HeroType getType() = 0;
    virtual void setAttributes(Personalisation personalisation) = 0;

    void setOwner(Player owner);
    Player getOwner() const;

private:
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
    Archer(unsigned int maxHealth, Weapon weapon, Wearable wearable) : Hero(maxHealth, weapon, wearable){};
    virtual ~Archer(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
    // jak dodać restrykcję co do Weapon?
};

class Knight : public Hero
{
public:
    Knight() : Hero(){};
    Knight(unsigned int maxHealth, Weapon weapon, Wearable wearable) : Hero(maxHealth, weapon, wearable){};
    virtual ~Knight(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
};

class Mage : public Hero
{
public:
    Mage() : Hero(){};
    Mage(unsigned int maxHealth, Weapon weapon, Wearable wearable) : Hero(maxHealth, weapon, wearable){};
    virtual ~Mage(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
    // jak dodać restrykcję co do Weapon?

    // funckja zadawania dmg przechodzącego przez kilka wrogów z pomniejszeniem wartości dmg
};

class IceDruid : public Hero
{
public:
    IceDruid() : Hero(){};
    IceDruid(unsigned int maxHealth, Weapon weapon, Wearable wearable) : Hero(maxHealth, weapon, wearable){};
    virtual ~IceDruid(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
    // jak dodać restrykcję co do Weapon?

    // zamraza Hero na cala nastepna runde, dodatkowo zadaje dmg
};

class Medic : public Hero
{
public:
    Medic() : Hero(){};
    Medic(unsigned int maxHealth, Weapon weapon, Wearable wearable) : Hero(maxHealth, weapon, wearable){};
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
    Ninja(unsigned int maxHealth, Weapon weapon, Wearable wearable) : Hero(maxHealth, weapon, wearable){};
    virtual ~Ninja(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);

    // jak dodać restrykcję co do Weapon?

    // moze co 2 pola sie ruszac, może zaatakować dwa cele
};

class Catapult : public Hero
{
public:
    Catapult() : Hero(){};
    Catapult(unsigned int maxHealth) : Hero(maxHealth){};
    virtual ~Catapult(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
    // nie zmienia połozenia, musi sie ladowac, moze strzelac co x tur, zadaje duże obrażenia jednorazowo na danym polu
};

class Trebuchet : public Hero
{
public:
    Trebuchet() : Hero(){};
    Trebuchet(unsigned int maxHealth) : Hero(maxHealth){};
    virtual ~Trebuchet(){};
    HeroType getType();
    void setAttributes(Personalisation personalisation);
    // Zadaje niewielkie obrażenia na pewnym obszarze przez kilka tur, stoi w jednym miejscu,
};

#endif

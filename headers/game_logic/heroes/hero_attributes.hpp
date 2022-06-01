#ifndef HERO_ATTRIBUTES_HPP
#define HERO_ATTRIBUTES_HPP
#include <map>
#include <tuple>

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

enum Personalisation
{
    Damage,
    Balanced,
    Range
};

struct Attributes
{
    unsigned int maxHealth;
    unsigned int moveRange;
    unsigned int weaponDamage;
    unsigned int weaponDurability;
    unsigned int weaponRange;
    unsigned int healing = 0;
};

typedef std::map<std::tuple<HeroType, Personalisation>, Attributes> HeroAttributes;

extern const HeroAttributes heroAttributes;

#endif
#include "../../../headers/game_logic/heroes/hero.hpp"

Hero::~Hero() {}

Hero::Hero()
{
    this->maxHealth = 0;
    this->currentHealth = 0;
}

Hero::Hero(unsigned int maxHealth, unsigned int moveRange)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->moveRange = moveRange;
}

Hero::Hero(unsigned int maxHealth, unsigned int moveRange, Weapon weapon, Wearable wearable)
{
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->moveRange = moveRange;
    this->weapon = std::make_optional<Weapon>(weapon);
    this->wearable = std::make_optional<Wearable>(wearable);
}

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

std::optional<Weapon> Hero::getWeapon() const
{
    return weapon;
}

std::optional<Wearable> Hero::getWearable() const
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

void Hero::addWeapon(Weapon weapon)
{
    this->weapon = std::make_optional<Weapon>(weapon);
}

void Hero::addWearable(Wearable wearable)
{
    this->wearable = std::make_optional<Wearable>(wearable);
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
    else
    {
        // TODO Do something if hero cannot be healed
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

Player Hero::getOwner() const
{
    return this->owner;
}

void Hero::setOwner(Player owner)
{
    this->owner = owner;
}

void Hero::setMoveRange(unsigned int range){
    this->moveRange = range;
}

void Hero::setPersonalisation(const Personalisation& personalisation)
{
    this->personalisation = personalisation;
}

HeroType Archer::getType()
{
    return EArcher;
}

void Archer::setAttributes()
{   Bow bow;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EArcher, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EArcher, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EArcher, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EArcher, Balanced));
        break;
    }
    bow.setDamage(attributes.weaponDamage);
    bow.setRange(attributes.weaponRange);
    bow.setDurability(attributes.weaponDurability);
    this->addWeapon(bow);
    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

HeroType Knight::getType()
{
    return EKnight;
}

void Knight::setAttributes()
{
    switch (personalisation)
    {
    case Damage:
        break;
    case Balanced:
        break;
    case Range:
        break;
    default:
        break;
    }
}

HeroType Mage::getType()
{
    return EWizard;
}

void Mage::setAttributes()
{
    switch (personalisation)
    {
    case Damage:
        break;
    case Balanced:
        break;
    case Range:
        break;
    default:
        break;
    }
}

HeroType IceDruid::getType()
{
    return EIceDruid;
}

void IceDruid::setAttributes()
{
    switch (personalisation)
    {
    case Damage:
        break;
    case Balanced:
        break;
    case Range:
        break;
    default:
        break;
    }
}

HeroType Medic::getType()
{
    return EMedic;
}

void Medic::setAttributes()
{
    switch (personalisation)
    {
    case Damage:
        break;
    case Balanced:
        break;
    case Range:
        break;
    default:
        break;
    }
}

HeroType Ninja::getType()
{
    return ENinja;
}

void Ninja::setAttributes()
{
    switch (personalisation)
    {
    case Damage:
        break;
    case Balanced:
        break;
    case Range:
        break;
    default:
        break;
    }
}

HeroType Catapult::getType()
{
    return ECatapult;
}

void Catapult::setAttributes()
{
    switch (personalisation)
    {
    case Damage:
        break;
    case Balanced:
        break;
    case Range:
        break;
    default:
        break;
    }
}

HeroType Trebuchet::getType()
{
    return ETrebuchet;
}

void Trebuchet::setAttributes()
{
    switch (personalisation)
    {
    case Damage:
        break;
    case Balanced:
        break;
    case Range:
        break;
    default:
        break;
    }
}

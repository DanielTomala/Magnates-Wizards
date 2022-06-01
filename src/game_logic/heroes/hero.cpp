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
    Sword sword;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EKnight, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EKnight, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EKnight, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EKnight, Balanced));
        break;
    }
    sword.setDamage(attributes.weaponDamage);
    sword.setRange(attributes.weaponRange);
    sword.setDurability(attributes.weaponDurability);
    this->addWeapon(sword);

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

HeroType Mage::getType()
{
    return EWizard;
}

void Mage::setAttributes()
{
    MageWand wand;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EWizard, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EWizard, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EWizard, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EWizard, Balanced));
        break;
    }
    wand.setDamage(attributes.weaponDamage);
    wand.setRange(attributes.weaponRange);
    wand.setDurability(attributes.weaponDurability);
    this->addWeapon(wand);

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

HeroType IceDruid::getType()
{
    return EIceDruid;
}

void IceDruid::setAttributes()
{
    IceDruidStaff staff;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EIceDruid, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EIceDruid, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EIceDruid, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EIceDruid, Balanced));
        break;
    }
    staff.setDamage(attributes.weaponDamage);
    staff.setRange(attributes.weaponRange);
    staff.setDurability(attributes.weaponDurability);
    this->addWeapon(staff);

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

HeroType Medic::getType()
{
    return EMedic;
}

void Medic::setAttributes()
{
    MedicalBox medicalBox;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(EMedic, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(EMedic, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(EMedic, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(EMedic, Balanced));
        break;
    }
    medicalBox.setDamage(attributes.weaponDamage);
    medicalBox.setRange(attributes.weaponRange);
    medicalBox.setDurability(attributes.weaponDurability);
    medicalBox.setMedicalHealth(attributes.healing);
    
    this->addWeapon(medicalBox);
    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

HeroType Ninja::getType()
{
    return ENinja;
}

void Ninja::setAttributes()
{
    Shuriken shuriken;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(ENinja, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(ENinja, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(ENinja, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(ENinja, Balanced));
        break;
    }
    shuriken.setDamage(attributes.weaponDamage);
    shuriken.setRange(attributes.weaponRange);
    shuriken.setDurability(attributes.weaponDurability);
    this->addWeapon(shuriken);

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

HeroType Catapult::getType()
{
    return ECatapult;
}

void Catapult::setAttributes()
{
    Stone stone;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(ECatapult, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(ECatapult, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(ECatapult, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(ECatapult, Balanced));
        break;
    }
    stone.setDamage(attributes.weaponDamage);
    stone.setRange(attributes.weaponRange);
    stone.setDurability(attributes.weaponDurability);
    this->addWeapon(stone);

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

HeroType Trebuchet::getType()
{
    return ETrebuchet;
}

void Trebuchet::setAttributes()
{
    Stone stone;
    Attributes attributes;
    switch (personalisation)
    {
    case Damage:
        attributes = heroAttributes.at(std::make_tuple(ETrebuchet, Damage));
        break;
    case Balanced:
        attributes = heroAttributes.at(std::make_tuple(ETrebuchet, Balanced));
        break;
    case Range:
        attributes = heroAttributes.at(std::make_tuple(ETrebuchet, Range));
        break;
    default:
        attributes = heroAttributes.at(std::make_tuple(ETrebuchet, Balanced));
        break;
    }
    stone.setDamage(attributes.weaponDamage);
    stone.setRange(attributes.weaponRange);
    stone.setDurability(attributes.weaponDurability);
    this->addWeapon(stone);

    this->setMaxHealth(attributes.maxHealth);
    this->setCurrentHealth(attributes.maxHealth);
    this->setMoveRange(attributes.moveRange);
}

#ifndef WEAPON_HPP
#define WEAPON_HPP

class Weapon
{
public:
    Weapon();
    Weapon(unsigned int damage, unsigned int durability, unsigned int range);
    virtual ~Weapon();

    unsigned int getDamage() const;
    unsigned int getDurability() const;
    unsigned int getRange() const;

    void setDamage(unsigned int damage);
    void setDurability(unsigned int durability);
    void setRange(unsigned int range);

    void takeDurabilityLoss(unsigned int durabilityPoints);
    bool isNotCrashed() const;

private:
    unsigned int damage;
    unsigned int durability;
    unsigned int range;
};

#endif
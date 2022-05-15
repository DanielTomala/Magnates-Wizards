#ifndef WEARABLE_HPP
#define WEARABLE_HPP

class Wearable
{
public:
    Wearable();
    Wearable(unsigned int protection, unsigned int durability);
    virtual ~Wearable();

    unsigned int getProtection() const;
    unsigned int getDurability() const;

    void setProtection(unsigned int protection);
    void setDurability(unsigned int durability);

    void takeDurabilityLoss(unsigned int durabilityPoints);
    bool isNotCrashed() const;

private:
    unsigned int protection;
    unsigned int durability;
};

#endif

#ifndef CATAPULT_HPP
#define CATAPULT_HPP

#include "./hero.hpp"

class Catapult : public Hero
{
public:
    Catapult() : Hero(){};
    Catapult(unsigned int maxHealth) : Hero(maxHealth, 0){};
    virtual ~Catapult(){};
    HeroType getType() const override;
    void setAttributes() override;
};
#endif

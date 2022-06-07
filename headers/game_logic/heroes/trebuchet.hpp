#ifndef TREBUCHET_HPP
#define TREBUCHET_HPP

#include "./hero.hpp"

class Trebuchet : public Hero
{
public:
    Trebuchet() : Hero(){};
    Trebuchet(unsigned int maxHealth) : Hero(maxHealth, 0){};
    virtual ~Trebuchet(){};
    HeroType getType() const override;
    void setAttributes() override;

};
#endif
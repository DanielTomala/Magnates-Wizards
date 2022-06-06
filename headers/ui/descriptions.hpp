#ifndef DESCRIPTIONS_HPP
#define DESCRIPTIONS_HPP

#include "../game_logic/heroes/hero.hpp"
#include "../game_logic/heroes/hero_attributes.hpp"

class Descriptions
/*
    class Description includes texts displaying in GUI
*/
{
private:
    std::map<HeroType, std::string> heroesDescriptions; // descriptions of heroes before choosen attributes
    std::map<std::tuple<HeroType, Personalisation>, std::string> personalisationDescriptions; //descriptions of heroes with choosen attributes
    std::string manual; // manual for players

public:
    Descriptions();
    ~Descriptions();

    std::string getManual() const;
    std::string getDescription(const HeroType &heroType) const;
    std::string getPersonalisationDescription(const std::tuple<HeroType, Personalisation> &data) const;
};

#endif

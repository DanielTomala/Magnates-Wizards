#ifndef DESCRIPTIONS_HPP
#define DESCRIPTIONS_HPP
#include "../game_logic/heroes/hero.hpp"
#include "../game_logic/heroes/hero_attributes.hpp"

class Descriptions
{
private:
    std::map<HeroType, std::string> heroesDescriptions;
    std::map<std::tuple<HeroType, Personalisation>, std::string> personalisationDescriptions;
    std::string manual;

public:
    Descriptions();
    ~Descriptions();

    std::string getManual() const;
    std::string getDescription(const HeroType &heroType) const;
    std::string getPersonalisationDescription(const std::tuple<HeroType, Personalisation> &data) const;
};

#endif

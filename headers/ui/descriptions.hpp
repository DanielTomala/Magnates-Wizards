#ifndef DESCRIPTIONS_HPP
#define DESCRIPTIONS_HPP
#include "../game_logic/heroes/hero.hpp"

class Descriptions{
    private:
        std::map<HeroType, std::string> heroesDescriptions;
    public:
        Descriptions();
        ~Descriptions();

        std::string getDescription(const HeroType &heroType) const;
};

#endif

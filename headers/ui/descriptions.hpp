#ifndef DESCRIPTIONS_HPP
#define DESCRIPTIONS_HPP
#include "../game_logic/heroes/hero.hpp"

class Descriptions{
    private:
        std::map<HeroType, std::string> heroesDescriptions;
        std::string manual;
    public:
        Descriptions();
        ~Descriptions();
        
        std::string getManual()const;
        std::string getDescription(const HeroType &heroType) const;
};

#endif
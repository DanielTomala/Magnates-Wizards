#include "../../headers/ui/descriptions.hpp"

//PRZYKŁADOWE WARTOŚCI
//NAJLEPIEJ BĘDZIE STWORZYĆ JAKIŚ CONFIG HEROSÓW

Descriptions::Descriptions(){
    this->heroesDescriptions[EArcher] = "Archer has a bow.\nAttack range: 1 - 3\nMove range: 1\nDamage: 10 - 50\n";
    this->heroesDescriptions[EKnight] = "Knight has sword.\nAttack range: 1\nMove range: 1\nDamage: 5 - 20\n";
    this->heroesDescriptions[EWizard] = "";
    this->heroesDescriptions[EIceDruid] = "";
    this->heroesDescriptions[EMedic] = "";
    this->heroesDescriptions[ECatapult] ="";
    this->heroesDescriptions[ENinja] ="";
    this->heroesDescriptions[ETrebuchet] ="";
}

Descriptions::~Descriptions(){}
        
std::string Descriptions::getDescription(const HeroType &heroType) const{
    return this->heroesDescriptions.at(heroType);
}

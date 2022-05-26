#include "../../headers/ui/descriptions.hpp"

//PRZYKŁADOWE WARTOŚCI 
//NAJLEPIEJ BĘDZIE STWORZYĆ JAKIŚ CONFIG HEROSÓW

Descriptions::Descriptions(){
    this->heroesDescriptions[EArcher] = "Archer has a bow.\n"\
                                        "Attack range: 1 - 3\n"\
                                        "Move range: 1\n"\
                                        "Damage: 5 - 20\n"\
                                        "HP: 50 - 100\n";
                                        
    this->heroesDescriptions[EKnight] = "Knight has sword.\n"\
                                        "Attack range: 1\n"\
                                        "Move range: 1\n"\
                                        "Damage: 30 - 50\n"\
                                        "HP: 200 - 300\n";

    this->heroesDescriptions[EWizard] = "Wizard can attack many heroes.\n"\
                                        "Damage decrease on each hero.\n"\
                                        "Attack range: all heroes\n"\
                                        "Move range: 1\n"\
                                        "Damage: 5 - 20\n";

    this->heroesDescriptions[EIceDruid] = "Ice Druid frozes hero\n"\
                                          "Attack range: 1 - 2\n"\
                                          "Move range: 1 - 2\n"\
                                          "Damage: 10 - 20\n"\
                                          "HP: 100 - 200\n";

    this->heroesDescriptions[EMedic] = "Medic can heal other heroes.\n"\
                                       "Heal range: any hero\n"\
                                       "Move range: 1 - 3\n"\
                                       "Damage: 1 - 100\n"\
                                       "HP: 50 - 100\n";

    this->heroesDescriptions[ECatapult] = "Powerful, static hero.\n"\
                                          "Can shoot every 3 rounds\n"\
                                          "Attack range: 2 - 5\n"\
                                          "Move range: 0\n"\
                                          "Damage: 50 - 100\n"\
                                          "HP: 100 - 200\n";

    this->heroesDescriptions[ENinja] =  "Fast, but weak hero\n"\
                                        "Can throw shurikens in 3 players.\n"\
                                        "Attack range: 1 - 3\n"\
                                        "Move range: 3 - 4\n"\
                                        "Damage: 10 - 30\n"\
                                        "HP: 50 - 100\n";

    this->heroesDescriptions[ETrebuchet] = "Powerful static hero.\n"\
                                           "Gives damage to few fields\n"\
                                           "Can shoot every 3 rounds\n"\
                                           "Attack range: 2 - 5\n"\
                                           "Move range: 0\n"\
                                           "Damage: 50 - 100\n"\
                                           "HP: 100 - 200\n";

    this->manual =  "MAGNATES & HEROES\n\n"\
                    "Game for 2 players.\n"\
                    "Each player has to choose 4 heroes.\n"\
                    "You can presonalise your heroes.\n"\
                    "Kill all opponent heroes to win.";
}

Descriptions::~Descriptions(){}

std::string Descriptions::getManual() const{
    return this->manual;
}

std::string Descriptions::getDescription(const HeroType &heroType) const{
    return this->heroesDescriptions.at(heroType);
}

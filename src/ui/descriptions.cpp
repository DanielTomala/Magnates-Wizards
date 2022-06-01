#include "../../headers/ui/descriptions.hpp"

// PRZYKŁADOWE WARTOŚCI
// NAJLEPIEJ BĘDZIE STWORZYĆ JAKIŚ CONFIG HEROSÓW

Descriptions::Descriptions()
{
    this->heroesDescriptions[EArcher] = "Archer has a bow.\n"
                                        "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Range)).weaponRange) + "\n"
                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).moveRange) + "\n"
                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).weaponDamage) + "\n"
                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).maxHealth) + "\n";

    this->heroesDescriptions[EKnight] = "Knight has sword.\n"
                                        "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EKnight, Balanced)).weaponRange) + "\n"
                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).moveRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Range)).moveRange) + "\n"
                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).weaponDamage) + "\n"
                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).maxHealth) + "\n";


    this->heroesDescriptions[EWizard] = "Wizard can attack many heroes.\n"
                                        "Damage decrease on each hero.\n"
                                        "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EWizard, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EWizard, Range)).weaponRange) + "\n"
                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EWizard, Damage)).moveRange) + "\n"
                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EWizard, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EWizard, Damage)).weaponDamage) + "\n"
                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EWizard, Damage)).maxHealth) + "\n";

    this->heroesDescriptions[EIceDruid] = "Ice Druid frozes hero\n"
                                          "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Range)).weaponRange) + "\n"
                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).moveRange) + "\n"
                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).weaponDamage) + "\n"
                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).maxHealth) + "\n";

    this->heroesDescriptions[EMedic] = "Medic can heal other heroes.\n"
                                       "Heal range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).weaponRange) + "\n"
                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).moveRange) + "\n"
                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).weaponDamage) + "\n"
                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).maxHealth) + "\n"
                                        "Healing: " +  std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).healing) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).healing)+ "\n";

    this->heroesDescriptions[ECatapult] = "Powerful, static hero.\n"
                                          "Can shoot every 3 rounds\n"
                                          "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Range)).weaponRange) + "\n"
                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).moveRange) + "\n"
                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).weaponDamage) + "\n"
                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).maxHealth) + "\n";


    this->heroesDescriptions[ENinja] = "Fast, but weak hero\n"
                                       "Can throw shurikens in 3 players.\n"
                                       "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Range)).weaponRange) + "\n"
                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).moveRange) + "\n"
                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).weaponDamage) + "\n"
                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).maxHealth) + "\n";


    this->heroesDescriptions[ETrebuchet] = "Powerful static hero.\n"
                                           "Gives damage to few fields\n"
                                           "Can shoot every 3 rounds\n"
                                           "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Range)).weaponRange) + "\n"
                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).moveRange) + "\n"
                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).weaponDamage) + "\n"
                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).maxHealth) + "\n";


    this->manual = "MAGNATES & HEROES\n\n"
                   "Game for 2 players.\n"
                   "Each player has to choose 4 heroes.\n"
                   "You can presonalise your heroes.\n"
                   "Kill all opponent heroes to win.";
}

Descriptions::~Descriptions() {}

std::string Descriptions::getManual() const
{
    return this->manual;
}

std::string Descriptions::getDescription(const HeroType &heroType) const
{
    return this->heroesDescriptions.at(heroType);
}

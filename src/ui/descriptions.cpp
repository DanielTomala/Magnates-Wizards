#include "../../headers/ui/descriptions.hpp"

Descriptions::Descriptions()
{
    this->heroesDescriptions[EArcher] = "Archer has a bow.\n"
                                        "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Range)).weaponRange) + "\n"
                                                                                                                                                                                                                   "Move range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).moveRange) + "\n"
                                                                                                                        "Damage: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EArcher, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).weaponDamage) + "\n"
                                                                                                                                                                                                                     "HP: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).maxHealth) + "\n";

    this->heroesDescriptions[EKnight] = "Knight has sword.\n"
                                        "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EKnight, Balanced)).weaponRange) + "\n"
                                                                                                                            "Move range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).moveRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Range)).moveRange) + "\n"
                                                                                                                                                                                                               "Damage: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EKnight, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).weaponDamage) + "\n"
                                                                                                                                                                                                                     "HP: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).maxHealth) + "\n";

    this->heroesDescriptions[EMage] = "Mage can attack many heroes.\n"
                                        "Damage decrease on other heroes.\n"
                                        "Attack range: " +
                                        std::to_string(heroAttributes.at(std::make_tuple(EMage, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Range)).weaponRange) + "\n"
                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Damage)).moveRange) + "\n"
                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Damage)).weaponDamage) + "\n"
                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Damage)).maxHealth) + "\n";

    this->heroesDescriptions[EIceDruid] = "Ice Druid frozes hero\n"
                                          "Attack range: " +
                                          std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Range)).weaponRange) + "\n"
                                                                                                                                                                                                                         "Move range: " +
                                          std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).moveRange) + "\n"
                                                                                                                            "Damage: " +
                                          std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).weaponDamage) + "\n"
                                                                                                                                                                                                                           "HP: " +
                                          std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).maxHealth) + "\n";

    this->heroesDescriptions[EMedic] = "Medic can heal other heroes.\n"
                                       "Heal range: " +
                                       std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).weaponRange) + "\n"
                                                                                                                                                                                                                "Move range: " +
                                       std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).moveRange) + "\n"
                                                                                                                      "Damage: " +
                                       std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).weaponDamage) + "\n"
                                                                                                                                                                                                                  "HP: " +
                                       std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).maxHealth) + "\n"
                                                                                                                      "Healing: " +
                                       std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).healing) + " - " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).healing) + "\n";

    this->heroesDescriptions[ECatapult] = "Powerful, static hero.\n"
                                          "Can shoot every 3 rounds\n"
                                          "Attack range: " +
                                          std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Range)).weaponRange) + "\n"
                                                                                                                                                                                                                         "Move range: " +
                                          std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).moveRange) + "\n"
                                                                                                                            "Damage: " +
                                          std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).weaponDamage) + "\n"
                                                                                                                                                                                                                           "HP: " +
                                          std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).maxHealth) + "\n";

    this->heroesDescriptions[ENinja] = "Fast, but weak hero\n"
                                       "Can throw shurikens in 3 players.\n"
                                       "Attack range: " +
                                       std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Range)).weaponRange) + "\n"
                                                                                                                                                                                                                "Move range: " +
                                       std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).moveRange) + "\n"
                                                                                                                      "Damage: " +
                                       std::to_string(heroAttributes.at(std::make_tuple(ENinja, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).weaponDamage) + "\n"
                                                                                                                                                                                                                  "HP: " +
                                       std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).maxHealth) + "\n";

    this->heroesDescriptions[ETrebuchet] = "Powerful static hero.\n"
                                           "Gives damage to few fields\n"
                                           "Can shoot every 3 rounds\n"
                                           "Attack range: " +
                                           std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).weaponRange) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Range)).weaponRange) + "\n"
                                                                                                                                                                                                                            "Move range: " +
                                           std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).moveRange) + "\n"
                                                                                                                              "Damage: " +
                                           std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Range)).weaponDamage) + " - " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).weaponDamage) + "\n"
                                                                                                                                                                                                                              "HP: " +
                                           std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).maxHealth) + "\n";


    this->personalisationDescriptions[std::make_tuple(EArcher, Damage)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Damage)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(EArcher, Balanced)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Balanced)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Balanced)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Balanced)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Balanced)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(EArcher, Range)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Range)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Range)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Range)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EArcher, Range)).maxHealth) + "\n";


    this->personalisationDescriptions[std::make_tuple(EKnight, Damage)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Damage)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(EKnight, Balanced)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Balanced)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Balanced)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Balanced)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Balanced)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(EKnight, Range)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Range)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Range)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Range)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EKnight, Range)).maxHealth) + "\n";


    this->personalisationDescriptions[std::make_tuple(EMage, Damage)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Damage)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Damage)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Damage)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Damage)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(EMage, Balanced)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Balanced)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Balanced)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Balanced)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Balanced)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(EMage, Range)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Range)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Range)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Range)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EMage, Range)).maxHealth) + "\n";


    this->personalisationDescriptions[std::make_tuple(ECatapult, Damage)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Damage)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(ECatapult, Balanced)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Balanced)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Balanced)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Balanced)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Balanced)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(ECatapult, Range)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Range)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Range)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Range)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ECatapult, Range)).maxHealth) + "\n";


    this->personalisationDescriptions[std::make_tuple(ETrebuchet, Damage)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Damage)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(ETrebuchet, Balanced)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Balanced)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Balanced)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Balanced)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Balanced)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(ETrebuchet, Range)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Range)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Range)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Range)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ETrebuchet, Range)).maxHealth) + "\n";


    this->personalisationDescriptions[std::make_tuple(ENinja, Damage)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Damage)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(ENinja, Balanced)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Balanced)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Balanced)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Balanced)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Balanced)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(ENinja, Range)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Range)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Range)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Range)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(ENinja, Range)).maxHealth) + "\n";


    this->personalisationDescriptions[std::make_tuple(EIceDruid, Damage)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Damage)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(EIceDruid, Balanced)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Balanced)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Balanced)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Balanced)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Balanced)).maxHealth) + "\n";

    this->personalisationDescriptions[std::make_tuple(EIceDruid, Range)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Range)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Range)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Range)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EIceDruid, Range)).maxHealth) + "\n";


     this->personalisationDescriptions[std::make_tuple(EMedic, Damage)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Damage)).maxHealth) + "\n"
                                                                        "Healing: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).healing) + "\n";

    this->personalisationDescriptions[std::make_tuple(EMedic, Balanced)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Balanced)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Balanced)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Balanced)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Balanced)).maxHealth) + "\n"
                                                                        "Healing: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Balanced)).healing) + "\n";

    this->personalisationDescriptions[std::make_tuple(EMedic, Range)] = "Attack range: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).weaponRange) + "\n"
                                                                        "Move range: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).moveRange) + "\n"
                                                                        "Damage: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).weaponDamage) + "\n"
                                                                        "HP: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).maxHealth) + "\n"
                                                                        "Healing: " + std::to_string(heroAttributes.at(std::make_tuple(EMedic, Range)).healing) + "\n";



    this->manual = "MAGNATES & HEROES\n\n"
                   "Game for 2 players.\n"
                   "Each player has to choose 4 heroes.\n"
                   "You can personalise your heroes\n"
                   "and set them on the chosen field.\n"
                   "Kill all opponent heroes to win.";
}

Descriptions::~Descriptions()
{
}

std::string Descriptions::getManual() const
{
    return this->manual;
}

std::string Descriptions::getDescription(const HeroType &heroType) const
{
    return this->heroesDescriptions.at(heroType);
}

std::string Descriptions::getPersonalisationDescription(const std::tuple<HeroType, Personalisation> &data) const
{
    return this->personalisationDescriptions.at(data);
}

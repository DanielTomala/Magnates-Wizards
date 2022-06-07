#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/game_logic/heroes/hero.hpp"
#include "../headers/game_logic/heroes/archer.hpp"
#include "../headers/game_logic/heroes/knight.hpp"
#include "../headers/game_logic/heroes/catapult.hpp"
#include "../headers/game_logic/heroes/ninja.hpp"
#include "../headers/game_logic/heroes/medic.hpp"
#include "../headers/game_logic/heroes/trebuchet.hpp"
#include "../headers/game_logic/heroes/mage.hpp"
#include "../headers/game_logic/heroes/iceDruid.hpp"
#include "../headers/game_logic/weapons/weapon.hpp"
#include "../headers/game_logic/wearable.hpp"
#include <optional>

TEST_CASE("Default Constructor", "[Archer]")
{
    Archer heroDefault;
    REQUIRE(heroDefault.getMaxHealth() == 0);
    REQUIRE(heroDefault.getCurrentHealth() == 0);
    REQUIRE(heroDefault.getWeapon() == std::nullopt);
    REQUIRE(heroDefault.getWearable() == std::nullopt);
}

TEST_CASE("Constructor with health", "[Archer]")
{
    Archer hero(20, 10);
    REQUIRE(hero.getMaxHealth() == 20);
    REQUIRE(hero.getCurrentHealth() == 20);
    REQUIRE(hero.getWeapon() == std::nullopt);
    REQUIRE(hero.getWearable() == std::nullopt);
}

TEST_CASE("Constructor with health, weapon and wearable", "[Archer]")
{
    auto weapon = std::make_shared<Weapon>(7, 60, 2);
    auto wearable = std::make_shared<Wearable>(10, 30);
    Archer hero(20, 10, weapon, wearable);
    REQUIRE(hero.getMaxHealth() == 20);
    REQUIRE(hero.getCurrentHealth() == 20);
    REQUIRE(hero.getWeapon().value()->getDamage() == weapon->getDamage());
    REQUIRE(hero.getWeapon().value()->getDurability() == weapon->getDurability());
    REQUIRE(hero.getWeapon().value()->getRange() == weapon->getRange());
    REQUIRE(hero.getWearable().value()->getDurability() == wearable->getDurability());
    REQUIRE(hero.getWearable().value()->getProtection() == wearable->getProtection());
}

TEST_CASE("Get and set max health", "[Archer]")
{
    Archer hero;
    REQUIRE(hero.getMaxHealth() == 0);
    hero.setMaxHealth(20);
    REQUIRE(hero.getMaxHealth() == 20);
}

TEST_CASE("Get and set current health", "[Archer]")
{
    Archer hero;
    REQUIRE(hero.getCurrentHealth() == 0);
    hero.setCurrentHealth(15);
    REQUIRE(hero.getCurrentHealth() == 15);
}

TEST_CASE("Get, add and remove weapon", "[Archer]")
{
    Archer hero;
    REQUIRE(hero.getWeapon() == std::nullopt);
    auto weapon = std::make_shared<Weapon>(7, 60, 2);
    hero.addWeapon(weapon);
    REQUIRE(hero.getWeapon().value()->getDamage() == weapon->getDamage());
    REQUIRE(hero.getWeapon().value()->getDurability() == weapon->getDurability());
    REQUIRE(hero.getWeapon().value()->getRange() == weapon->getRange());
    hero.removeWeapon();
    REQUIRE(hero.getWeapon() == std::nullopt);
}

TEST_CASE("Get, add and remove wearable", "[Archer]")
{
    Archer hero;
    REQUIRE(hero.getWearable() == std::nullopt);
    auto wearable = std::make_shared<Wearable>(10, 30);
    hero.addWearable(wearable);
    REQUIRE(hero.getWearable().value()->getDurability() == wearable->getDurability());
    REQUIRE(hero.getWearable().value()->getProtection() == wearable->getProtection());
    hero.removeWearable();
    REQUIRE(hero.getWearable() == std::nullopt);
}

TEST_CASE("Heal; health after heal less than max", "[Archer]")
{
    Archer hero(45, 12);
    hero.setCurrentHealth(30);
    REQUIRE(hero.getCurrentHealth() == 30);
    hero.heal(10);
    REQUIRE(hero.getCurrentHealth() == 40);
}

TEST_CASE("Heal; try to heal more points than max", "[Archer]")
{
    Archer hero(65, 12);
    hero.setCurrentHealth(50);
    REQUIRE(hero.getCurrentHealth() == 50);
    hero.heal(20);
    REQUIRE(hero.getCurrentHealth() == 65);
}

TEST_CASE("Heal; already max health points", "[Archer]")
{
    Archer hero(20, 12);
    REQUIRE(hero.getCurrentHealth() == 20);
    hero.heal(5);
    REQUIRE(hero.getCurrentHealth() == 20);
}

TEST_CASE("Heal; already health points == 0", "[Archer]")
{
    Archer hero(20, 12);
    hero.setCurrentHealth(0);
    REQUIRE(hero.getCurrentHealth() == 0);
    hero.heal(10);
    REQUIRE(hero.getCurrentHealth() == 0);
}

TEST_CASE("Take damage; after damage health > 0", "[Archer]")
{
    Archer hero(35, 12);
    REQUIRE(hero.getCurrentHealth() == 35);
    hero.takeDamage(5);
    REQUIRE(hero.getCurrentHealth() == 30);
}

TEST_CASE("Take damage; after damage health =< 0", "[Archer]")
{
    Archer hero(80, 12);
    REQUIRE(hero.getCurrentHealth() == 80);
    hero.takeDamage(100);
    REQUIRE(hero.getCurrentHealth() == 0);
}

TEST_CASE("Take damage; before damage health ==  0", "[Archer]")
{
    Archer hero(80, 12);
    hero.setCurrentHealth(0);
    REQUIRE(hero.getCurrentHealth() == 0);
    hero.takeDamage(17);
    REQUIRE(hero.getCurrentHealth() == 0);
}

TEST_CASE("Is alive", "[Archer]")
{
    Archer hero(80, 12);
    REQUIRE(hero.isAlive() == true);
    hero.setCurrentHealth(0);
    REQUIRE(hero.isAlive() == false);
}

TEST_CASE("Archer", "[Archer]")
{
    Archer archer(100, 2);
    REQUIRE(archer.getType() == EArcher);
    REQUIRE(archer.getCurrentHealth() == 100);
    REQUIRE(archer.getMoveRange() == 2);
    archer.takeDamage(1);
    REQUIRE(archer.getCurrentHealth() == 99);
    archer.setCurrentHealth(0);
    REQUIRE(archer.isAlive() == false);
}

TEST_CASE("Knight", "[Knight]")
{
    Knight knight(10, 1);
    REQUIRE(knight.getType() == EKnight);
    REQUIRE(knight.getCurrentHealth() == 10);
    REQUIRE(knight.getMoveRange() == 1);
    knight.takeDamage(1);
    REQUIRE(knight.getCurrentHealth() == 9);
    knight.setCurrentHealth(0);
    REQUIRE(knight.isAlive() == false);
}

TEST_CASE("Mage", "[Mage]")
{
    Mage mage(10, 5);
    REQUIRE(mage.getType() == EMage);
    REQUIRE(mage.getCurrentHealth() == 10);
    REQUIRE(mage.getMoveRange() == 5);
    mage.setCurrentHealth(0);
    REQUIRE(mage.isAlive() == false);
}

TEST_CASE("IceDruid", "[IceDruid]")
{
    IceDruid icedruid(150, 3);
    REQUIRE(icedruid.getType() == EIceDruid);
    REQUIRE(icedruid.getCurrentHealth() == 150);
    REQUIRE(icedruid.getMoveRange() == 3);
    icedruid.takeDamage(10);
    REQUIRE(icedruid.getCurrentHealth() == 140);
    icedruid.setCurrentHealth(0);
    REQUIRE(icedruid.isAlive() == false);
}

TEST_CASE("Ninja", "[Ninja]")
{
    Ninja ninja(200, 5);
    REQUIRE(ninja.getType() == ENinja);
    REQUIRE(ninja.getCurrentHealth() == 200);
    REQUIRE(ninja.getMoveRange() == 5);
    ninja.takeDamage(10);
    REQUIRE(ninja.getCurrentHealth() == 190);
    ninja.setCurrentHealth(0);
    REQUIRE(ninja.isAlive() == false);
}

TEST_CASE("Medic", "[Medic]")
{
    Medic medic(100, 3);
    REQUIRE(medic.getType() == EMedic);
    REQUIRE(medic.getCurrentHealth() == 100);
    REQUIRE(medic.getMoveRange() == 3);
    medic.takeDamage(10);
    REQUIRE(medic.getCurrentHealth() == 90);
    medic.setCurrentHealth(0);
    REQUIRE(medic.isAlive() == false);
}

TEST_CASE("Trebuchet", "[Trebuchet]")
{
    Trebuchet trebuchet(100);
    REQUIRE(trebuchet.getType() == ETrebuchet);
    REQUIRE(trebuchet.getCurrentHealth() == 100);
    REQUIRE(trebuchet.getMaxHealth() == 100);
    trebuchet.takeDamage(10);
    REQUIRE(trebuchet.getCurrentHealth() == 90);
}

TEST_CASE("Catapult", "[Catapult]")
{
    Catapult catapult(150);
    REQUIRE(catapult.getType() == ECatapult);
    REQUIRE(catapult.getCurrentHealth() == 150);
    catapult.takeDamage(10);
    REQUIRE(catapult.getCurrentHealth() == 140);
}
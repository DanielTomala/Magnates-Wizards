#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/hero.hpp"
#include "../headers/weapon.hpp"
#include "../headers/wearable.hpp"
#include <optional>

TEST_CASE("Default Constructor", "[Hero]")
{
    Hero heroDefault;
    REQUIRE(heroDefault.getMaxHealth() == 0);
    REQUIRE(heroDefault.getCurrentHealth() == 0);
    REQUIRE(heroDefault.getWeapon() == std::nullopt);
    REQUIRE(heroDefault.getWearable() == std::nullopt);
}

TEST_CASE("Constructor with health", "[Hero]")
{
    Hero hero(20);
    REQUIRE(hero.getMaxHealth() == 20);
    REQUIRE(hero.getCurrentHealth() == 20);
    REQUIRE(hero.getWeapon() == std::nullopt);
    REQUIRE(hero.getWearable() == std::nullopt);
}

TEST_CASE("Constructor with health, weapon and wearable", "[Hero]")
{
    Weapon weapon(7, 60, 2);
    Wearable wearable(10, 30);
    Hero hero(20, weapon, wearable);
    REQUIRE(hero.getMaxHealth() == 20);
    REQUIRE(hero.getCurrentHealth() == 20);
    REQUIRE(hero.getWeapon().value().getDamage() == weapon.getDamage());
    REQUIRE(hero.getWeapon().value().getDurability() == weapon.getDurability());
    REQUIRE(hero.getWeapon().value().getRange() == weapon.getRange());
    REQUIRE(hero.getWearable().value().getDurability() == wearable.getDurability());
    REQUIRE(hero.getWearable().value().getProtection() == wearable.getProtection());
}

TEST_CASE("Get and set max health", "[Hero]")
{
    Hero hero;
    REQUIRE(hero.getMaxHealth() == 0);
    hero.setMaxHealth(20);
    REQUIRE(hero.getMaxHealth() == 20);
}

TEST_CASE("Get and set current health", "[Hero]")
{
    Hero hero;
    REQUIRE(hero.getCurrentHealth() == 0);
    hero.setCurrentHealth(15);
    REQUIRE(hero.getCurrentHealth() == 15);
}

TEST_CASE("Get, add and remove weapon", "[Hero]")
{
    Hero hero;
    REQUIRE(hero.getWeapon() == std::nullopt);
    Weapon weapon(4, 60, 2);
    hero.addWeapon(weapon);
    REQUIRE(hero.getWeapon()->getDamage() == weapon.getDamage());
    REQUIRE(hero.getWeapon()->getDurability() == weapon.getDurability());
    REQUIRE(hero.getWeapon()->getRange() == weapon.getRange());
    hero.removeWeapon();
    REQUIRE(hero.getWeapon() == std::nullopt);
}

TEST_CASE("Get, add and remove wearable", "[Hero]")
{
    Hero hero;
    REQUIRE(hero.getWearable() == std::nullopt);
    Wearable wearable(5, 70);
    hero.addWearable(wearable);
    REQUIRE(hero.getWearable()->getDurability() == wearable.getDurability());
    REQUIRE(hero.getWearable()->getProtection() == wearable.getProtection());
    hero.removeWearable();
    REQUIRE(hero.getWearable() == std::nullopt);
}

TEST_CASE("Heal; health after heal less than max", "[Hero]")
{
    Hero hero(45);
    hero.setCurrentHealth(30);
    REQUIRE(hero.getCurrentHealth() == 30);
    hero.heal(10);
    REQUIRE(hero.getCurrentHealth() == 40);
}

TEST_CASE("Heal; try to heal more points than max", "[Hero]")
{
    Hero hero(65);
    hero.setCurrentHealth(50);
    REQUIRE(hero.getCurrentHealth() == 50);
    hero.heal(20);
    REQUIRE(hero.getCurrentHealth() == 65);
}

TEST_CASE("Heal; already max health points", "[Hero]")
{
    Hero hero(20);
    REQUIRE(hero.getCurrentHealth() == 20);
    hero.heal(5);
    REQUIRE(hero.getCurrentHealth() == 20);
}

TEST_CASE("Heal; already health points == 0", "[Hero]")
{
    Hero hero(20);
    hero.setCurrentHealth(0);
    REQUIRE(hero.getCurrentHealth() == 0);
    hero.heal(10);
    REQUIRE(hero.getCurrentHealth() == 0);
}

TEST_CASE("Take damage; after damage health > 0", "[Hero]")
{
    Hero hero(35);
    REQUIRE(hero.getCurrentHealth() == 35);
    hero.takeDamage(5);
    REQUIRE(hero.getCurrentHealth() == 30);
}

TEST_CASE("Take damage; after damage health =< 0", "[Hero]")
{
    Hero hero(80);
    REQUIRE(hero.getCurrentHealth() == 80);
    hero.takeDamage(100);
    REQUIRE(hero.getCurrentHealth() == 0);
}

TEST_CASE("Take damage; before damage health ==  0", "[Hero]")
{
    Hero hero(80);
    hero.setCurrentHealth(0);
    REQUIRE(hero.getCurrentHealth() == 0);
    hero.takeDamage(17);
    REQUIRE(hero.getCurrentHealth() == 0);
}

TEST_CASE("Is alive", "[Hero]")
{
    Hero hero(80);
    REQUIRE(hero.isAlive() == true);
    hero.setCurrentHealth(0);
    REQUIRE(hero.isAlive() == false);
}

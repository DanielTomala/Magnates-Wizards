#define CATCH_CONFIG_MAIN

#include <optional>
#include "catch.hpp"
#include "../headers/hero.hpp"

TEST_CASE("Default Constructor", "[Hero]")
{
    Hero heroDefault = Hero();
    REQUIRE(heroDefault.getMaxHealth() == 0);
    REQUIRE(heroDefault.getCurrentHealth() == 0);
    REQUIRE(heroDefault.getWeapon() == std::nullopt);
    REQUIRE(heroDefault.getWearable() == std::nullopt);
}

TEST_CASE("Constructor with health", "[Hero]")
{
    Hero hero = Hero(20);
    REQUIRE(hero.getMaxHealth() == 20);
    REQUIRE(hero.getCurrentHealth() == 20);
    REQUIRE(hero.getWeapon() == std::nullopt);
    REQUIRE(hero.getWearable() == std::nullopt);
}

TEST_CASE("Constructor with health, weapon and wearable", "[Hero]")
{
    Weapon weapon = Weapon(7, 60, 2);
    Wearable wearable = Wearable(10, 30);
    Hero hero = Hero(20, weapon, wearable);
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
    Hero hero = Hero();
    REQUIRE(hero.getMaxHealth() == 0);
    hero.setMaxHealth(20);
    REQUIRE(hero.getMaxHealth() == 20);
}

TEST_CASE("Get and set current health", "[Hero]")
{
    Hero hero = Hero();
    REQUIRE(hero.getCurrentHealth() == 0);
    hero.setCurrentHealth(15);
    REQUIRE(hero.getCurrentHealth() == 15);
}

TEST_CASE("Get and set weapon", "[Hero]")
{
    Hero hero = Hero();
    REQUIRE(hero.getWeapon() == std::nullopt);
    Weapon weapon = Weapon(4, 60, 2);
    REQUIRE(hero.getWeapon().value().getDamage() == weapon.getDamage());
    REQUIRE(hero.getWeapon().value().getDurability() == weapon.getDurability());
    REQUIRE(hero.getWeapon().value().getRange() == weapon.getRange());
}

TEST_CASE("Get and set wearable", "[Hero]")
{
    Hero hero = Hero();
    REQUIRE(hero.getWearable() == std::nullopt);
    Wearable wearable = Wearable(5, 70);
    REQUIRE(hero.getWearable().value().getDurability() == wearable.getDurability());
    REQUIRE(hero.getWearable().value().getProtection() == wearable.getProtection());
}

TEST_CASE("Heal; health after heal less than max", "[Hero]")
{
    Hero hero = Hero(45);
    hero.setCurrentHealth(30);
    REQUIRE(hero.getCurrentHealth() == 30);
    hero.heal(10);
    REQUIRE(hero.getCurrentHealth() == 40);
}

TEST_CASE("Heal; try to heal more points than max", "[Hero]")
{
    Hero hero = Hero(65);
    hero.setCurrentHealth(50);
    REQUIRE(hero.getCurrentHealth() == 50);
    hero.heal(20);
    REQUIRE(hero.getCurrentHealth() == 65);
}

TEST_CASE("Heal; already max health points", "[Hero]")
{
    Hero hero = Hero(20);
    REQUIRE(hero.getCurrentHealth() == 20);
    hero.heal(5);
    REQUIRE(hero.getCurrentHealth() == 20);
}

TEST_CASE("Heal; already health points == 0", "[Hero]")
{
    Hero hero = Hero(20);
    hero.setCurrentHealth(0);
    REQUIRE(hero.getCurrentHealth() == 0);
    hero.heal(10);
    REQUIRE(hero.getCurrentHealth() == 0);
}

TEST_CASE("Take damage; after damage health > 0", "[Hero]")
{
    Hero hero = Hero(35);
    REQUIRE(hero.getCurrentHealth() == 35);
    hero.takeDamage(5);
    REQUIRE(hero.getCurrentHealth() == 30);
}

TEST_CASE("Take damage; after damage health =< 0", "[Hero]")
{
    Hero hero = Hero(80);
    REQUIRE(hero.getCurrentHealth() == 80);
    hero.takeDamage(100);
    REQUIRE(hero.getCurrentHealth() == 0);
}

TEST_CASE("Take damage; before damage health ==  0", "[Hero]")
{
    Hero hero = Hero(80);
    hero.setCurrentHealth(0);
    REQUIRE(hero.getCurrentHealth() == 0);
    hero.takeDamage(17);
    REQUIRE(hero.getCurrentHealth() == 0);
}

TEST_CASE("Is alive", "[Hero]")
{
    Hero hero = Hero(80);
    REQUIRE(hero.isAlive() == true);
    hero.setCurrentHealth(0);
    REQUIRE(hero.isAlive() == false);
}

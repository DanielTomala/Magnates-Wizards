#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/hero.hpp"
#include "../headers/weapon.hpp"
#include "../headers/wearable.hpp"

TEST_CASE("Default constructor", "[Weapon]")
{
    Weapon weapon;
    REQUIRE(weapon.getDamage() == 0);
    REQUIRE(weapon.getDurability() == 0);
    REQUIRE(weapon.getRange() == 0);
}

TEST_CASE("Constructor with all arguments", "[Weapon]")
{
    Weapon weapon(8, 50, 2);
    REQUIRE(weapon.getDamage() == 8);
    REQUIRE(weapon.getDurability() == 50);
    REQUIRE(weapon.getRange() == 2);
}

TEST_CASE("Get and set damage", "[Weapon]")
{
    Weapon weapon;
    REQUIRE(weapon.getDamage() == 0);
    weapon.setDamage(4);
    REQUIRE(weapon.getDamage() == 4);
}

TEST_CASE("Get and set durability", "[Weapon]")
{
    Weapon weapon;
    REQUIRE(weapon.getDurability() == 0);
    weapon.setDurability(20);
    REQUIRE(weapon.getDurability() == 20);
}

TEST_CASE("Get and set range", "[Weapon]")
{
    Weapon weapon;
    REQUIRE(weapon.getRange() == 0);
    weapon.setRange(3);
    REQUIRE(weapon.getRange() == 3);
}

TEST_CASE("Take durability loss; after loss durability > 0", "[Weapon]"){
    Weapon weapon(11, 30, 2);
    REQUIRE(weapon.getDurability() == 30);
    weapon.takeDurabilityLoss(10);
    REQUIRE(weapon.getDurability() == 20);
}

TEST_CASE("Take durability loss; after loss durability =< 0", "[Weapon]"){
    Weapon weapon(11, 30, 2);
    REQUIRE(weapon.getDurability() == 30);
    weapon.takeDurabilityLoss(55);
    REQUIRE(weapon.getDurability() == 0);
}

TEST_CASE("Take durability loss; before loss durability == 0", "[Weapon]"){
    Weapon weapon(11, 30, 2);
    weapon.setDurability(0);
    REQUIRE(weapon.getDurability() == 0);
    weapon.takeDurabilityLoss(17);
    REQUIRE(weapon.getDurability() == 0);
}

TEST_CASE("Is not crashed", "[Weapon]"){
    Weapon weapon(11, 30, 2);
    REQUIRE(weapon.isNotCrashed() == true);
    weapon.setDurability(0);
    REQUIRE(weapon.isNotCrashed() == false);
}

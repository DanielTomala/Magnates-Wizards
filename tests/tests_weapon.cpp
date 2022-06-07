#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/game_logic/weapons/weapon.hpp"
#include "../headers/game_logic/weapons/bow.hpp"
#include "../headers/game_logic/weapons/ice_druid_staff.hpp"
#include "../headers/game_logic/weapons/mage_wand.hpp"
#include "../headers/game_logic/weapons/medical_box.hpp"
#include "../headers/game_logic/weapons/shuriken.hpp"
#include "../headers/game_logic/weapons/stone.hpp"
#include "../headers/game_logic/weapons/sword.hpp"

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

TEST_CASE("Take durability loss; after loss durability > 0", "[Weapon]")
{
    Weapon weapon(11, 30, 2);
    REQUIRE(weapon.getDurability() == 30);
    weapon.takeDurabilityLoss(10);
    REQUIRE(weapon.getDurability() == 20);
}

TEST_CASE("Take durability loss; after loss durability =< 0", "[Weapon]")
{
    Weapon weapon(11, 30, 2);
    REQUIRE(weapon.getDurability() == 30);
    weapon.takeDurabilityLoss(55);
    REQUIRE(weapon.getDurability() == 0);
}

TEST_CASE("Take durability loss; before loss durability == 0", "[Weapon]")
{
    Weapon weapon(11, 30, 2);
    weapon.setDurability(0);
    REQUIRE(weapon.getDurability() == 0);
    weapon.takeDurabilityLoss(17);
    REQUIRE(weapon.getDurability() == 0);
}

TEST_CASE("Is not crashed", "[Weapon]")
{
    Weapon weapon(11, 30, 2);
    REQUIRE(weapon.isNotCrashed() == true);
    weapon.setDurability(0);
    REQUIRE(weapon.isNotCrashed() == false);
}

TEST_CASE("Sword", "[Sword]")
{
    Sword sword;
    // Sword sword(10, 10, 1);
    // REQUIRE(sword.getDamage() == 10);
    // REQUIRE(sword.getDurability() == 10);
    // REQUIRE(sword.getRange() == 1);
    REQUIRE(sword.getType() == ESword);
    // sword.setDamage(1);
    // REQUIRE(sword.getDamage() == 1);
}

TEST_CASE("MagicWand", "[MagicWand]")
{
    MageWand wand;
    REQUIRE(wand.getType() == EMagicWand);
}

TEST_CASE("Bow", "[Bow]")
{
    Bow bow;
    // Bow bow(11, 30, 2);
    REQUIRE(bow.getType() == EBow);
    // REQUIRE(bow.getDamage() == 11);
    // REQUIRE(bow.getDurability() == 30);
    // REQUIRE(bow.getRange() == 2);
}

TEST_CASE("IceDruidStaff", "[IceDruidStaff]")
{
    IceDruidStaff ice_druid_staff;
    REQUIRE(ice_druid_staff.getType() == EIceDruidStaff);
}

TEST_CASE("MedicalBox", "[IceDruidStaff]")
{
    MedicalBox medicalbox;
    REQUIRE(medicalbox.getType() == EMedicalBox);
}

TEST_CASE("Stone", "[Stone]")
{
    Stone stone;
    REQUIRE(stone.getType() == EStone);
}

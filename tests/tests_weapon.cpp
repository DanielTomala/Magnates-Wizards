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

TEST_CASE("Sword - type", "[Sword]")
{
    Sword sword;
    sword.setDamage(150);
    REQUIRE(sword.getDamage() == 150);
    sword.setDurability(10);
    REQUIRE(sword.getDurability() == 10);
    sword.setRange(1);
    REQUIRE(sword.getRange() == 1);
    REQUIRE(sword.getType() == ESword);
}

TEST_CASE("MagicWand - type", "[MagicWand]")
{
    MageWand wand;
    REQUIRE(wand.getType() == EMagicWand);
    wand.setDamage(50);
    REQUIRE(wand.getDamage() == 50);
    wand.setDurability(1);
    REQUIRE(wand.getDurability() == 1);
    wand.setRange(3);
    REQUIRE(wand.getRange() == 3);
}

TEST_CASE("Bow - type", "[Bow]")
{
    Bow bow;
    REQUIRE(bow.getType() == EBow);
    bow.setDamage(100);
    REQUIRE(bow.getDamage() == 100);
    bow.setDurability(10);
    REQUIRE(bow.getDurability() == 10);
    bow.setRange(3);
    REQUIRE(bow.getRange() == 3);
}

TEST_CASE("IceDruidStaff - type", "[IceDruidStaff]")
{
    IceDruidStaff ice_druid_staff;
    REQUIRE(ice_druid_staff.getType() == EIceDruidStaff);
    ice_druid_staff.setLockedFields(3);
    REQUIRE(ice_druid_staff.getLockedFields() == 3);
    ice_druid_staff.setFreezeTime(2);
    REQUIRE(ice_druid_staff.getFreezeTime() == 2);
}

TEST_CASE("MedicalBox - type", "[IceDruidStaff]")
{
    MedicalBox medicalbox;
    REQUIRE(medicalbox.getType() == EMedicalBox);
    medicalbox.setMedicalHealth(10);
    REQUIRE(medicalbox.getHealPoints() == 10);
    medicalbox.subtractMedicalHealth(5);
    REQUIRE(medicalbox.getHealPoints() == 5);
}

TEST_CASE("Stone - type", "[Stone]")
{
    Stone stone;
    REQUIRE(stone.getType() == EStone);
}

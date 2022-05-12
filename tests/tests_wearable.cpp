#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/wearable.hpp"

TEST_CASE("Default constructor", "[Wearable]")
{
    Wearable wearable;
    REQUIRE(wearable.getProtection() == 0);
    REQUIRE(wearable.getDurability() == 0);
}

TEST_CASE("Constructor with all arguments", "[Wearable]")
{
    Wearable wearable(10, 50);
    REQUIRE(wearable.getProtection() == 10);
    REQUIRE(wearable.getDurability() == 50);

}

TEST_CASE("Get and set durability", "[Wearable]")
{
    Wearable wearable;
    REQUIRE(wearable.getDurability() == 0);
    wearable.setDurability(20);
    REQUIRE(wearable.getDurability() == 20);
}

TEST_CASE("Get and set protection", "[Wearable]")
{
    Wearable wearable;
    REQUIRE(wearable.getProtection() == 0);
    wearable.setProtection(3);
    REQUIRE(wearable.getProtection() == 3);
}

TEST_CASE("Take durability loss; after loss durability > 0", "[Wearable]"){
    Wearable wearable(11, 30);
    REQUIRE(wearable.getDurability() == 30);
    wearable.takeDurabilityLoss(10);
    REQUIRE(wearable.getDurability() == 20);
}

TEST_CASE("Take durability loss; after loss durability =< 0", "[Wearable]"){
    Wearable wearable(11, 30);
    REQUIRE(wearable.getDurability() == 30);
    wearable.takeDurabilityLoss(55);
    REQUIRE(wearable.getDurability() == 0);
}

TEST_CASE("Take durability loss; before loss durability == 0", "[Wearable]"){
    Wearable wearable(11, 30);
    wearable.setDurability(0);
    REQUIRE(wearable.getDurability() == 0);
    wearable.takeDurabilityLoss(17);
    REQUIRE(wearable.getDurability() == 0);
}

TEST_CASE("Is not crashed", "[Wearable]"){
    Wearable wearable(11, 30);
    REQUIRE(wearable.isNotCrashed() == true);
    wearable.setDurability(0);
    REQUIRE(wearable.isNotCrashed() == false);
}

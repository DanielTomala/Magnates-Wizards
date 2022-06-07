#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/game_logic/heroes/hero.hpp"
#include "../headers/game_logic/heroes/archer.hpp"
#include "../headers/game_logic/field.hpp"

TEST_CASE("Default constructor", "[Field]")
{
    Field field = Field();
    REQUIRE(field.getHero() == std::nullopt);
    REQUIRE(field.getFieldBooster() == std::nullopt);
    REQUIRE(field.getBubbleBooster() == std::nullopt);
}

TEST_CASE("Constructor with all arguments", "[Field]")
{
    FieldBooster field_booster = FieldBooster();
    BubbleBooster bubble_booster = BubbleBooster();
    auto hero = std::make_shared<Archer>();
    Field field = Field(hero, field_booster, bubble_booster);
    REQUIRE(field.getHero() == hero);
    REQUIRE(field.getFieldBooster() != std::nullopt);
    REQUIRE(field.getBubbleBooster() != std::nullopt);
}

TEST_CASE("Is free", "[Field]")
{
    Field field = Field();
    REQUIRE(field.isFree() == true);
    auto hero = std::make_shared<Archer>();
    field.addHero(hero);
    REQUIRE(field.isFree() == false);
}

TEST_CASE("Is bubble boosted", "[Field]")
{
    Field field = Field();
    REQUIRE(field.isBubbleBoosted() == false);
    BubbleBooster bubble_booster = BubbleBooster();
    field.addBubbleBooster(bubble_booster);
    REQUIRE(field.isBubbleBoosted() == true);
}

TEST_CASE("Is field boosted", "[Field]")
{
    Field field = Field();
    REQUIRE(field.isFieldBoosted() == false);
    FieldBooster field_booster = FieldBooster();
    field.addFieldBooster(field_booster);
    REQUIRE(field.isFieldBoosted() == true);
}

TEST_CASE("Get hero", "[Field]")
{
    FieldBooster field_booster = FieldBooster();
    BubbleBooster bubble_booster = BubbleBooster();
    auto hero = std::make_shared<Archer>();
    Field field = Field(hero, field_booster, bubble_booster);
    REQUIRE(field.getHero() == hero);
}

TEST_CASE("Get field booster", "[Field]")
{
    FieldBooster field_booster = FieldBooster();
    BubbleBooster bubble_booster = BubbleBooster();
    auto hero = std::make_shared<Archer>();
    Field field = Field(hero, field_booster, bubble_booster);
    REQUIRE(field.getFieldBooster() != std::nullopt);
}

TEST_CASE("Get bubble booster", "[Field]")
{
    FieldBooster field_booster = FieldBooster();
    BubbleBooster bubble_booster = BubbleBooster();
    auto hero = std::make_shared<Archer>();
    Field field = Field(hero, field_booster, bubble_booster);
    REQUIRE(field.getBubbleBooster() != std::nullopt);
}

TEST_CASE("Add hero", "[Field]")
{
    Field field = Field();
    auto hero = std::make_shared<Archer>();
    field.addHero(hero);
    REQUIRE(field.isFree() == false);
}

TEST_CASE("Add field booster", "[Field]")
{
    Field field = Field();
    FieldBooster field_booster = FieldBooster();
    field.addFieldBooster(field_booster);
    REQUIRE(field.isFieldBoosted() == true);
}

TEST_CASE("Add bubble booster", "[Field]")
{
    Field field = Field();
    BubbleBooster bubble_booster = BubbleBooster();
    field.addBubbleBooster(bubble_booster);
    REQUIRE(field.isBubbleBoosted() == true);
}

TEST_CASE("Remove hero", "[Field]")
{
    Field field = Field();
    REQUIRE(field.isFree() == true);
    auto hero = std::make_shared<Archer>();
    field.addHero(hero);
    REQUIRE(field.isFree() == false);
    field.removeHero();
    REQUIRE(field.isFree() == true);
}

TEST_CASE("Remove field booster", "[Field]")
{
    Field field = Field();
    REQUIRE(field.isFieldBoosted() == false);
    FieldBooster field_booster = FieldBooster();
    field.addFieldBooster(field_booster);
    REQUIRE(field.isFieldBoosted() == true);
    field.removeFieldBooster();
    REQUIRE(field.isFieldBoosted() == false);
}

TEST_CASE("Remove bubble booster", "[Field]")
{
    Field field = Field();
    REQUIRE(field.isBubbleBoosted() == false);
    BubbleBooster bubble_booster = BubbleBooster();
    field.addBubbleBooster(bubble_booster);
    REQUIRE(field.isBubbleBoosted() == true);
    field.removeBubbleBooster();
    REQUIRE(field.isBubbleBoosted() == false);
}

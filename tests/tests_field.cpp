#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/game_logic/heroes/hero.hpp"
#include "../headers/game_logic/heroes/archer.hpp"
#include "../headers/game_logic/field.hpp"

TEST_CASE("Default constructor", "[Field]")
{
    Field field;
    REQUIRE(field.getHero() == std::nullopt);
    REQUIRE(field.getFieldBooster() == std::nullopt);
    REQUIRE(field.getBubbleBooster() == std::nullopt);
}

TEST_CASE("Constructor with all arguments", "[Field]")
{
    FieldBooster field_booster;
    BubbleBooster bubble_booster;

    Archer archer;
    auto hero_ptr = std::make_shared<Archer>(archer);
    Field field = Field(std::make_optional<std::shared_ptr<Hero>>(hero_ptr), std::make_optional<FieldBooster>(field_booster), std::make_optional<BubbleBooster>(bubble_booster));
    REQUIRE(field.getHero().value() == hero_ptr);
    REQUIRE(field.getFieldBooster() != std::nullopt);
    REQUIRE(field.getBubbleBooster() != std::nullopt);
}

TEST_CASE("Is free", "[Field]")
{
    Field field;
    REQUIRE(field.isFree() == true);
    Archer archer;
    auto hero_ptr = std::make_shared<Archer>(archer);
    field.addHero(hero_ptr);
    REQUIRE(field.isFree() == false);
}

TEST_CASE("Is bubble boosted", "[Field]")
{
    Field field;
    REQUIRE(field.isBubbleBoosted() == false);
    BubbleBooster bubble_booster;
    field.addBubbleBooster(bubble_booster);
    REQUIRE(field.isBubbleBoosted() == true);
}

TEST_CASE("Is field boosted", "[Field]")
{
    Field field;
    REQUIRE(field.isFieldBoosted() == false);
    FieldBooster field_booster;
    field.addFieldBooster(field_booster);
    REQUIRE(field.isFieldBoosted() == true);
}

TEST_CASE("Get hero", "[Field]")
{
    FieldBooster field_booster;
    BubbleBooster bubble_booster;
    Archer archer;
    auto hero_ptr = std::make_shared<Archer>(archer);
    Field field = Field(std::make_optional<std::shared_ptr<Hero>>(hero_ptr), std::make_optional<FieldBooster>(field_booster), std::make_optional<BubbleBooster>(bubble_booster));
    REQUIRE(field.getHero().value() == hero_ptr);
}

TEST_CASE("Get field booster", "[Field]")
{
    FieldBooster field_booster;
    BubbleBooster bubble_booster;
    Archer archer;
    auto hero_ptr = std::make_shared<Archer>(archer);
    Field field = Field(std::make_optional<std::shared_ptr<Hero>>(hero_ptr), std::make_optional<FieldBooster>(field_booster), std::make_optional<BubbleBooster>(bubble_booster));
    REQUIRE(field.getFieldBooster() != std::nullopt);
}

TEST_CASE("Get bubble booster", "[Field]")
{
    FieldBooster field_booster;
    BubbleBooster bubble_booster;
    Archer archer;
    auto hero_ptr = std::make_shared<Archer>(archer);
    Field field = Field(std::make_optional<std::shared_ptr<Hero>>(hero_ptr), std::make_optional<FieldBooster>(field_booster), std::make_optional<BubbleBooster>(bubble_booster));
    REQUIRE(field.getBubbleBooster() != std::nullopt);
}

TEST_CASE("Add hero", "[Field]")
{
    Field field;
    Archer archer;
    auto hero_ptr = std::make_shared<Archer>(archer);
    field.addHero(hero_ptr);
    REQUIRE(field.isFree() == false);
}

TEST_CASE("Add field booster", "[Field]")
{
    Field field;
    FieldBooster field_booster;
    field.addFieldBooster(field_booster);
    REQUIRE(field.isFieldBoosted() == true);
}

TEST_CASE("Add bubble booster", "[Field]")
{
    Field field;
    BubbleBooster bubble_booster;
    field.addBubbleBooster(bubble_booster);
    REQUIRE(field.isBubbleBoosted() == true);
}

TEST_CASE("Remove hero", "[Field]")
{
    Field field;
    REQUIRE(field.isFree() == true);
    Archer archer;
    auto hero_ptr = std::make_shared<Archer>(archer);
    field.addHero(hero_ptr);
    REQUIRE(field.isFree() == false);
    field.removeHero();
    REQUIRE(field.isFree() == true);
}

TEST_CASE("Remove field booster", "[Field]")
{
    Field field;
    REQUIRE(field.isFieldBoosted() == false);
    FieldBooster field_booster;
    field.addFieldBooster(field_booster);
    REQUIRE(field.isFieldBoosted() == true);
    field.removeFieldBooster();
    REQUIRE(field.isFieldBoosted() == false);
}

TEST_CASE("Remove bubble booster", "[Field]")
{
    Field field;
    REQUIRE(field.isBubbleBoosted() == false);
    BubbleBooster bubble_booster;
    field.addBubbleBooster(bubble_booster);
    REQUIRE(field.isBubbleBoosted() == true);
    field.removeBubbleBooster();
    REQUIRE(field.isBubbleBoosted() == false);
}

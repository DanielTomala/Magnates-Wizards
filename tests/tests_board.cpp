#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/game_logic/board.hpp"
#include "../headers/game_logic/heroes/archer.hpp"
#include "../headers/game_logic/heroes/knight.hpp"


TEST_CASE("Default Constructor", "[Board]")
{
}

TEST_CASE("Get rows and columns number", "[Board]")
{
	Board board;
	REQUIRE(board.getRowsNumber() == 6);
	REQUIRE(board.getColumnsNumber() == 10);
}

TEST_CASE("Get field by coordinate. Proper coordinates", "[Board]")
{
}

TEST_CASE("Get field by coordinate. Wrong coordintate", "[Board]")
{
}

TEST_CASE("Get fields", "[Board]")
{
}

TEST_CASE("Get fields with heroes", "[Board]")
{
	Board board;
	auto knight = std::make_shared<Knight>();
	auto archer = std::make_shared<Archer>();
	std::vector<std::shared_ptr<Field>> fields;
	fields.push_back(std::move(board.getFieldByCoordinate(0, 0)));
	fields.push_back(std::move(board.getFieldByCoordinate(1, 1)));
	board.getFieldByCoordinate(0, 0)->addHero(knight);
	board.getFieldByCoordinate(1, 1)->addHero(archer);
	REQUIRE(fields == board.getFieldsWithHeroes());
}

TEST_CASE("Get fields with bubble boosters", "[Board]")
{
}

TEST_CASE("Get fields with field boosters", "[Board]")
{
}
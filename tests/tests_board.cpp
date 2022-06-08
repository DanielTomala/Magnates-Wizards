#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/game_logic/board.hpp"
#include "../headers/game_logic/heroes/archer.hpp"
#include "../headers/game_logic/heroes/knight.hpp"

TEST_CASE("Default Constructor", "[Board]")
{
	Board board;
	REQUIRE(board.getFields()[0][0]->getHero() == std::nullopt);
}

TEST_CASE("Get rows and columns number", "[Board]")
{
	Board board;
	REQUIRE(board.getRowsNumber() == BOARD_ROWS);
	REQUIRE(board.getColumnsNumber() == BOARD_COLUMNS);
}

TEST_CASE("Get field by coordinate. Proper coordinates", "[Board]")
{
	Board board;
	REQUIRE(board.getFieldByCoordinate(0, 0)->isFree() == true);
	REQUIRE(board.getFieldByCoordinate(1, 1)->isFree() == true);
	Archer archer;
	auto archer_ptr = std::make_shared<Archer>(archer);
	board.getFieldByCoordinate(1, 1)->addHero(archer_ptr);
	REQUIRE(board.getFieldByCoordinate(1, 1)->isFree() == false);
}

TEST_CASE("Get field by coordinate. Wrong coordintate", "[Board]")
{
	Board board;
	REQUIRE_THROWS_AS(board.getFieldByCoordinate(20, 20), std::invalid_argument);
	Archer archer(50, 2);
	Knight knight(120, 1);
	auto archer_ptr = std::make_shared<Archer>(archer);
	auto knight_ptr = std::make_shared<Knight>(knight);
	board.getFields()[0][2]->addHero(archer_ptr);
	board.getFields()[3][4]->addHero(knight_ptr);
	REQUIRE(board.getFieldByCoordinate(0, 2)->getHero().value() == archer_ptr);
	REQUIRE(board.getFieldByCoordinate(3, 4)->getHero().value() == knight_ptr);
}

TEST_CASE("Get fields with heroes", "[Board]")
{
	Board board;
	Knight knight(100, 2);
	auto knight_ptr = std::make_shared<Knight>(knight);
	Archer archer(30, 3);
	auto archer_ptr = std::make_shared<Archer>(archer);
	std::vector<std::shared_ptr<Field>> fields;
	fields.push_back(std::move(board.getFieldByCoordinate(0, 0)));
	fields.push_back(std::move(board.getFieldByCoordinate(1, 1)));
	board.getFieldByCoordinate(0, 0)->addHero(knight_ptr);
	board.getFieldByCoordinate(1, 1)->addHero(archer_ptr);
	REQUIRE(fields == board.getFieldsWithHeroes());
}

TEST_CASE("Get fields with bubble boosters", "[Board]")
{
	Board board;
	BubbleBooster heal ;
	BubbleBooster takedmg;
	std::vector<std::shared_ptr<Field>> fields;
	fields.push_back(std::move(board.getFieldByCoordinate(0, 0)));
	fields.push_back(std::move(board.getFieldByCoordinate(1, 1)));
	board.getFieldByCoordinate(0, 0)->addBubbleBooster(heal);
	board.getFieldByCoordinate(1, 1)->addBubbleBooster(takedmg);
	REQUIRE(fields == board.getFieldsWithBubbleBooster());
}

TEST_CASE("Get fields with field boosters", "[Board]")
{
	Board board;
	auto heal = FieldBooster();
	auto takedmg = FieldBooster();
	std::vector<std::shared_ptr<Field>> fields;
	fields.push_back(std::move(board.getFieldByCoordinate(0, 0)));
	fields.push_back(std::move(board.getFieldByCoordinate(1, 1)));
	board.getFieldByCoordinate(0, 0)->addFieldBooster(heal);
	board.getFieldByCoordinate(1, 1)->addFieldBooster(takedmg);
	REQUIRE(fields == board.getFieldsWithFieldBooster());
}

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/game_logic/board.hpp"

TEST_CASE("Default Constructor", "[Board]")
{
}

TEST_CASE("Get rows and columns number", "[Board]")
{
	Board board();
	REQUIRE(board.getRowsNumber() == 6)
	REQUIRE(board.getColumnsNumber() == 10)
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
}

TEST_CASE("Get fields with bubble boosters", "[Board]")
{
}

TEST_CASE("Get fields with field boosters", "[Board]")
{
}
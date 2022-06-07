#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "../headers/game_logic/board.hpp"

TEST_CASE("Default Constructor", "[Board]")
{

}

TEST_CASE("Get rows and columns number", "[Board]"){

}

TEST_CASE("Get field by coordinate. Proper coordinates", "[Board]"){

}

TEST_CASE("Get field by coordinate. Wrong coordintate", "[Board]"){

}

TEST_CASE("Get fields", "[Board]"){

}

TEST_CASE("Get fields with heroes", "[Board]"){
    Board board;
    std::vector<std::shared_ptr<Hero>> heroes;
    Archer hero1();
    board.getFields()[0][0]->addHero(std::make_shared<Hero>(hero1));
    heroes.push_back(std::make_shared<Hero>(hero1));
}

TEST_CASE("Get fields with bubble boosters", "[Board]"){


}

TEST_CASE("Get fields with field boosters", "[Board]"){

}
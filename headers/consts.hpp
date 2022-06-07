#ifndef CONSTS_HPP
#define CONSTS_HPP

#include <array>
#include <memory>
#include "./game_logic/field.hpp"
#include <SFML/Graphics.hpp>

const unsigned int ACTIONS_PER_TURN = 5;
const unsigned int BOARD_COLUMNS = 10;
const unsigned int BOARD_ROWS = 6;
const unsigned int FIELD_SIZE = 100;
const unsigned int NINJA_LOADS_NUMBER = 3;
const unsigned int ICE_DRUID_LOADS_NUMBER = 1;
const unsigned int SIEGE_LOADS_NUMBER = 3;
const unsigned int TREBUCHET_ATTACK_TURNS = 1;
const sf::Vector2f ONE_ACTION_SIZE = sf::Vector2f(60, 60);
const sf::Vector2f TWO_ACTION_SIZE = sf::Vector2f(115, 60);
const sf::Vector2f THREE_ACTION_SIZE = sf::Vector2f(170, 60);

typedef std::array<std::array<std::shared_ptr<Field>, BOARD_COLUMNS>, BOARD_ROWS> FieldsArray;

#endif
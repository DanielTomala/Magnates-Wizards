#ifndef CONSTS_HPP
#define CONSTS_HPP

#include <array>
#include <memory>
#include "field.hpp"
#include <SFML/Graphics.hpp>

const unsigned int ACTIONS_PER_TURN = 5;
const unsigned int BOARD_COLUMNS = 10;
const unsigned int BOARD_ROWS = 6;
const unsigned int FIELD_SIZE = 100;

typedef std::array<std::array<std::shared_ptr<Field>, BOARD_COLUMNS>, BOARD_ROWS> FieldsArray;



#endif
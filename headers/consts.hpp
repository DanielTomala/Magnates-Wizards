#ifndef CONSTS_HPP
#define CONSTS_HPP

#include <array>
#include <memory>
#include "field.hpp"

const unsigned int BOARD_COLUMNS = 10;
const unsigned int BOARD_ROWS = 6;
const unsigned int ACTIONS_PER_TURN = 5;
typedef std::array<std::array<Field&, BOARD_COLUMNS>, BOARD_ROWS> FieldsArray;

enum HeroType{
    EHero,
    EArcher,
    EKnight,
    EMage,
    EIceDruid,
    EGroundDruid,
    ECatapult,
    EMedic,
    ENinja,
    ETrebuchet
};

#endif
#ifndef BOARD_HPP
#define BOARD_HPP

#include "field.hpp"

class Board {
private:
    Field fields[5][9];
public:
    Field GetField(unsigned int x, unsigned int y) const;
    Field GetBoard() const;
};

#endif
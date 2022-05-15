#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <array>
#include "field.hpp"
#include "consts.hpp"

class Board
{
private:
    FieldsArray fields;

public:
    Board();
    unsigned int getRowsNumber() const;
    unsigned int getColumnsNumber() const;
    Field& getFieldByCoordinate(unsigned int row, unsigned int column) const;
    FieldsArray getFields() const;
    std::vector<Field&> getFieldsWithHeroes() const;
    std::vector<Field&> getFieldsWithBubbleBooster() const;
    std::vector<Field&> getFieldsWithFieldBooster() const;
};

#endif
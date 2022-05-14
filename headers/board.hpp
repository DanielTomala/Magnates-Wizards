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
    std::shared_ptr<Field> getFieldByCoordinate(unsigned int x, unsigned int y) const;
    FieldsArray getFields() const;
    std::vector<std::shared_ptr<Field>> getFieldsWithHeroes() const;
    std::vector<std::shared_ptr<Field>> getFieldsWithBubbleBooster() const;
    std::vector<std::shared_ptr<Field>> getFieldsWithFieldBooster() const;
};

#endif
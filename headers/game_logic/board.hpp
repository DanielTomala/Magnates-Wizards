#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include <array>
#include <memory>

#include "./field.hpp"
#include "../consts.hpp"

class Board
{
private:
    FieldsArray fields;

public:
    Board();
    Board(FieldsArray fields);
    unsigned int getRowsNumber() const;
    unsigned int getColumnsNumber() const;
    FieldsArray getFields() const;
    std::shared_ptr<Field> getFieldByCoordinate(unsigned int row, unsigned int column) const;
    std::vector<std::shared_ptr<Field>> getFieldsWithHeroes() const;
    std::vector<std::shared_ptr<Field>> getFieldsWithBubbleBooster() const;
    std::vector<std::shared_ptr<Field>> getFieldsWithFieldBooster() const;
    std::vector<std::shared_ptr<Field>> getFieldsAround(std::shared_ptr<Field> field) const;
    std::tuple<int, int> findFieldCoordinates(std::shared_ptr<Field> field) const;
};

#endif
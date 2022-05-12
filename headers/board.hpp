#ifndef BOARD_HPP
#define BOARD_HPP

#include <vector>
#include "field.hpp"

class Board {
private:
    int width=5;
    int length=9;
    Field fields[length][width];
public:
    int getWidth() const;
    int getLength() const;
    Field getFieldByCoordinate(unsigned int x, unsigned int y) const;
    Field getFields() const;
    std::vector<Field> getFieldsWithHeroes() const;
    std::vector<Field> getFieldsWithBubbleBoost() const;
    std::vector<Field> getFieldsWithFieldBoost() const;
};

#endif
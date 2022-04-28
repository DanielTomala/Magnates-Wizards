#include <vector>
#include "board.hpp"

Field Board::getFieldByCoordinate(unsigned int x, unsigned int y) const
{
    if (x > this->width or y > this->length)
    {
        throw std::invalid_argument("X value has to be less than width and Y value has to be less than length");
    }
    return this->fields[x][y];
}

Field Board::getFields() const
{
    return this->fields;
}

int Board::getLength() const
{
    return this->length;
}

int Board::getWidth() const
{
    return this->width;
}

vector<Field> Board::getFieldsWithHeroes() const
{
    vector<Field> fieldsWithHeroes;
    for (int y=0, y<this->width, y++)
    {
        for (int x=0, x<this->length, x++)
    }
}
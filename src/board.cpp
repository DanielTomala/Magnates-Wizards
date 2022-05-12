#include <vector>
#include "../headers/board.hpp"

Board::Board() {}

Board::Board(Field fields[length][width])
{
    this->fields[length][width] = fields[length][width];
}

Field Board::getFieldByCoordinate(unsigned int x, unsigned int y) const
{
    if (x >= this->width || y >= this->length)
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

std::vector<Field> Board::getFieldsWithHeroes() const
{
    std::vector<Field> fieldsWithHeroes;
    for (Field field : this->fields)
    {
        if (field.isFree() == false)
        {
            fieldsWithHeroes.push_back(field);
        }
    }
}

std::vector<Field> Board::getFieldsWithBubbleBoost() const
{
    std::vector<Field> fieldsWithBubbleBoost;
    for (Field field : this->fields)
    {
        if (field.isBubbleBoosted() == true)
        {
            fieldsWithBubbleBoost.push_back(field);
        }
    }
    return fieldsWithBubbleBoost;
}

std::vector<Field> Board::getFieldsWithFieldBoost() const
{
    std::vector<Field> fieldsWithFieldBoost;
    for (Field field : this->fields)
    {
        if (field.isFieldBoosted() == true)
        {
            fieldsWithFieldBoost.push_back(field);
        }
    }
    return fieldsWithFieldBoost;
}
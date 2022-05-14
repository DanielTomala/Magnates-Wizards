#include <vector>
#include "../headers/board.hpp"

Board::Board() {}

Field Board::getFieldByCoordinate(unsigned int row, unsigned int column) const
{
    if (row >= this->getRowsNumber() || column >= this->getColumnsNumber())
    {
        throw std::invalid_argument("X value has to be less than width and Y value has to be less than length");
    }
    return this->fields.at(row).at(column);
}

FieldsArray Board::getFields() const
{
    return this->fields;
}

unsigned int Board::getRowsNumber() const
{
    return BOARD_ROWS;
}

unsigned int Board::getColumnsNumber() const
{
    return BOARD_COLUMNS;
}
std::vector<Field> Board::getFieldsWithHeroes() const
{
    std::vector<Field> fieldsWithHeroes;
    for (auto row : this->fields)
    {
        for (auto field : row)
        {
            if (field.isFree() == false)
            {
                fieldsWithHeroes.push_back(field);
            }
        }
    }
    return fieldsWithHeroes;
}

std::vector<Field> Board::getFieldsWithBubbleBooster() const
{
    std::vector<Field> fieldsWithBubbleBooster;
    for (auto row : this->fields)
    {
        for (auto field : row)
        {
            if (field.isBubbleBoosted() == true)
            {
                fieldsWithBubbleBooster.push_back(field);
            }
        }
    }
    return fieldsWithBubbleBooster;
}

std::vector<Field> Board::getFieldsWithFieldBooster() const
{
    std::vector<Field> fieldsWithFieldBooster;
    for (auto row : this->fields)
    {
        for (auto field : row)
        {
            if (field.isFieldBoosted() == true)
            {
                fieldsWithFieldBooster.push_back(field);
            }
        }
    }
    return fieldsWithFieldBooster;
}
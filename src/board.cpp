#include <vector>
#include "board.hpp"

Board::Board(){}

Board::Board(Field fields[length][width])
{
    this->fields[length][width] = fields[length][width];
}

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
        {
            if (this->fields[y][x].isFree == false)
            {
                fieldsWithHeroes.push_back(fields[y][x]);
            }
        }
    }
    return fieldsWithHeroes;
}

vector<Field> Board::getFieldsWithBubbleBoost() const
{
    vector<Field> fieldsWithBubbleBoost;
    for (int y=0, y<this->width, y++)
    {
        for (int x=0, x<this->length, x++)
        {
            if (this->fields[y][x].isBubbleBoosted == true)
            {
                fieldsWithBubbleBoost.push_back(fields[y][x]);
            }
        }
    }
    return fieldsWithBubbleBoost;
}

vector<Field> Board::getFieldsWithFieldBoost() const
{
    vector<Field> fieldsWithFieldBoost;
    for (int y=0, y<this->width, y++)
    {
        for (int x=0, x<this->length, x++)
        {
            if (this->fields[y][x].isFieldBoosted == true)
            {
                fieldsWithFieldBoost.push_back(fields[y][x]);
            }
        }
    }
    return fieldsWithFieldBoost;
}
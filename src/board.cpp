#include "board.hpp"

Field Board::GetField(unsigned int x, unsigned int y) const
{
    if (x > 5 or y > 9)
    {
        throw std::invalid_argument("X value has to be less than 5 and Y value has to be less than 9");
    }
    return this->fields[x][y];
}

Field Board::GetBoard() const
{
    return this->fields;
}
